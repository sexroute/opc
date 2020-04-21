namespace DxpSimpleAPI
{
    using OpcRcw.Comn;
    using OpcRcw.Da;
    using System;
    using System.Collections;
    using System.Collections.Generic;

    using System.Runtime.InteropServices;

    public class DxpSimpleClass
    {
        private static readonly uint CLSCTX_ALL = (((CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER) | CLSCTX_LOCAL_SERVER) | CLSCTX_REMOTE_SERVER);
        private static readonly uint CLSCTX_INPROC_HANDLER = 2;
        private static readonly uint CLSCTX_INPROC_SERVER = 1;
        private static readonly uint CLSCTX_LOCAL_SERVER = 4;
        private static readonly uint CLSCTX_REMOTE_SERVER = 0x10;
        private static readonly Guid CLSID_DA_20 = new Guid("63D5F432-CFE4-11d1-B2C8-0060083BA1FB");
        private static readonly Guid CLSID_DA_30 = new Guid("CC603642-66D7-48f1-B69A-B625E73652D7");
        private static readonly Guid CLSID_SERVERLIST = new Guid("13486D51-4821-11D2-A494-3CB306C10000");
        private static readonly Guid IID_IUnknown = new Guid("00000000-0000-0000-C000-000000000046");
        private bool m_bConnect = false;
        private Dictionary<int, cGroupObject> m_dicGroup = new Dictionary<int, cGroupObject>();
        private IOPCServer m_OPCServer;

        private SERVERPARAM[] BrowseServer(string sNodeName, out int nServerCnt)
        {
            SERVERPARAM[] serverparamArray2;
            nServerCnt = 0;
            IOPCServerList svrList = (IOPCServerList) CreateInstance(CLSID_SERVERLIST, sNodeName);
            try
            {
                Guid catid = CLSID_DA_30;
                serverparamArray2 = this.GetServerParam(svrList, catid, out nServerCnt);
            }
            catch (Exception)
            {
                serverparamArray2 = null;
            }
            finally
            {
                Marshal.ReleaseComObject(svrList);
                svrList = null;
            }
            return serverparamArray2;
        }

        [DllImport("ole32.dll")]
        private static extern void CoCreateInstanceEx(ref Guid clsid, [MarshalAs(UnmanagedType.IUnknown)] object punkOuter, uint dwClsCtx, [In] ref COSERVERINFO pServerInfo, uint dwCount, [In, Out] MULTI_QI[] pResults);
        public bool Connect(string sNodeName, string sServerName)
        {
            bool flag;
            if (this.m_OPCServer != null)
            {
                return true;
            }
            IOPCServerList loOpcServer = (IOPCServerList) CreateInstance(CLSID_SERVERLIST, sNodeName);
            try
            {
                Guid guid;
                loOpcServer.CLSIDFromProgID(sServerName, out guid);
                this.m_OPCServer = (IOPCServer) CreateInstance(guid, sNodeName);
                if (this.m_OPCServer != null)
                {
                    ((IOPCCommon) this.m_OPCServer).SetClientName("TestClient");
                    this.m_bConnect = true;
                    return true;
                }
                flag = false;
            }
            catch (Exception e)
            {
                flag = false;
               
            }
            finally
            {
                Marshal.ReleaseComObject(loOpcServer);
                loOpcServer = null;
            }
            return flag;
        }

        private static object CreateInstance(Guid clsid, string hostName)
        {
            COSERVERINFO pServerInfo = new COSERVERINFO();
            MULTI_QI[] pResults = new MULTI_QI[1];
            GCHandle handle = GCHandle.Alloc(IID_IUnknown, GCHandleType.Pinned);
            pResults[0].iid = handle.AddrOfPinnedObject();
            pResults[0].pItf = null;
            pResults[0].hr = 0;
            try
            {
                uint dwClsCtx = CLSCTX_ALL;
                pServerInfo.pwszName = hostName;
                CoCreateInstanceEx(ref clsid, null, dwClsCtx, ref pServerInfo, 1, pResults);
            }
            catch (Exception)
            {
                return null;
            }
            handle.Free();
            return pResults[0].pItf;
        }

        public bool Disconnect()
        {
            if (this.m_OPCServer == null)
            {
                return true;
            }
            try
            {
                foreach (cGroupObject obj2 in this.m_dicGroup.Values)
                {
                    if (obj2.m_OPCConnPoint != null)
                    {
                        Marshal.ReleaseComObject(obj2.m_OPCConnPoint);
                        obj2.m_OPCConnPoint = null;
                    }
                    if (obj2.m_iServerGroup != 0)
                    {
                        this.m_OPCServer.RemoveGroup(obj2.m_iServerGroup, 0);
                        obj2.m_iServerGroup = 0;
                    }
                    if (obj2.m_OPCGroup != null)
                    {
                        Marshal.ReleaseComObject(obj2.m_OPCGroup);
                        obj2.m_OPCGroup = null;
                    }
                }
                this.m_dicGroup.Clear();
                Marshal.ReleaseComObject(this.m_OPCServer);
                this.m_OPCServer = null;
                this.m_bConnect = false;
                return true;
            }
            catch (Exception)
            {
                this.m_bConnect = false;
                return false;
            }
        }

        public bool EnumServerList(string sNodeName, out string[] sServerNameArray)
        {
            try
            {
                int num;
                SERVERPARAM[] serverparamArray = this.BrowseServer(sNodeName, out num);
                sServerNameArray = new string[num];
                for (int i = 0; i < num; i++)
                {
                    sServerNameArray[i] = serverparamArray[i].progID;
                }
                return true;
            }
            catch (Exception)
            {
                sServerNameArray = new string[] { "" };
                return false;
            }
        }

        private SERVERPARAM[] GetServerParam(IOPCServerList svrList, Guid catid, out int nServerCnt)
        {
            IEnumGUID ppenumClsid = null;
            Guid[] rgcatidImpl = new Guid[] { catid };
            svrList.EnumClassesOfCategories(1, rgcatidImpl, 0, null, out ppenumClsid);
            ArrayList list = new ArrayList();
            int pceltFetched = 0;
            Guid[] rgelt = new Guid[100];
            nServerCnt = 0;
            do
            {
                try
                {
                    ppenumClsid.Next(rgelt.Length, rgelt, out pceltFetched);
                    for (int i = 0; i < pceltFetched; i++)
                    {
                        SERVERPARAM serverparam;
                        serverparam.clsid = rgelt[i];
                        svrList.GetClassDetails(ref serverparam.clsid, out serverparam.progID, out serverparam.description);
                        list.Add(serverparam);
                        nServerCnt++;
                    }
                }
                catch
                {
                    break;
                }
            }
            while (pceltFetched > 0);
            Marshal.ReleaseComObject(ppenumClsid);
            ppenumClsid = null;
            return (SERVERPARAM[]) list.ToArray(typeof(SERVERPARAM));
        }

        public bool Read(string[] sItemIDArray, out object[] oValueArray, out short[] wQualityArray, out OpcRcw.Da.FILETIME[] fTimeArray, out int[] nErrorArray)
        {
            int dwCount = sItemIDArray.Length;
            int[] pdwMaxAge = new int[dwCount];
            for (int i = 0; i < dwCount; i++)
            {
                pdwMaxAge[i] = 0;
            }
            int[] numArray2 = new int[dwCount];
            oValueArray = new object[dwCount];
            wQualityArray = new short[dwCount];
            fTimeArray = new OpcRcw.Da.FILETIME[dwCount];
            nErrorArray = new int[dwCount];
            try
            {
                IntPtr ptr;
                IntPtr ptr2;
                IntPtr ptr3;
                IntPtr ptr4;
                ((IOPCItemIO) this.m_OPCServer).Read(dwCount, sItemIDArray, pdwMaxAge, out ptr, out ptr2, out ptr3, out ptr4);
                IntPtr pSrcNativeVariant = ptr;
                IntPtr ptr6 = ptr3;
                Marshal.Copy(ptr4, nErrorArray, 0, dwCount);
                Marshal.Copy(ptr2, wQualityArray, 0, dwCount);
                for (int j = 0; j < dwCount; j++)
                {
                    if (numArray2[j] == 0)
                    {
                        oValueArray[j] = Marshal.GetObjectForNativeVariant(pSrcNativeVariant);
                    }
                    else
                    {
                        oValueArray[j] = "Error Value";
                    }
                    fTimeArray[j] = (OpcRcw.Da.FILETIME) Marshal.PtrToStructure(ptr6, typeof(OpcRcw.Da.FILETIME));
                    VariantClear(pSrcNativeVariant);
                    Marshal.DestroyStructure(ptr6, typeof(OpcRcw.Da.FILETIME));
                    pSrcNativeVariant = (IntPtr) (pSrcNativeVariant.ToInt32() + 0x10);
                    ptr6 = (IntPtr) (ptr6.ToInt32() + Marshal.SizeOf(typeof(OpcRcw.Da.FILETIME)));
                }
                Marshal.FreeCoTaskMem(ptr);
                Marshal.FreeCoTaskMem(ptr3);
                Marshal.FreeCoTaskMem(ptr4);
                Marshal.FreeCoTaskMem(ptr2);
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        [DllImport("oleaut32.dll")]
        private static extern void VariantClear(IntPtr pVariant);
        public bool Write(string[] sItemIDArray, object[] oValArray, out int[] nErrorArray)
        {
            int dwCount = sItemIDArray.Length;
            nErrorArray = new int[dwCount];
            try
            {
                IntPtr ptr;
                IOPCItemIO oPCServer = (IOPCItemIO) this.m_OPCServer;
                OPCITEMVQT[] pItemVQT = new OPCITEMVQT[dwCount];
                for (int i = 0; i < oValArray.Length; i++)
                {
                    pItemVQT[i] = new OPCITEMVQT { vDataValue = oValArray[i] };
                }
                oPCServer.WriteVQT(dwCount, sItemIDArray, pItemVQT, out ptr);
                Marshal.Copy(ptr, nErrorArray, 0, dwCount);
                Marshal.FreeCoTaskMem(ptr);
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        private class cGroupObject
        {
            public bool m_bAdvise = false;
            public int m_iCallBackConnection = 0;
            public int m_iClientGroup = 0;
            public int m_iServerGroup = 0;
            public IConnectionPoint m_OPCConnPoint = null;
            public IOPCGroupStateMgt m_OPCGroup = null;
        }

        [StructLayout(LayoutKind.Sequential, CharSet=CharSet.Auto)]
        private struct COSERVERINFO
        {
            public uint dwReserved1;
            [MarshalAs(UnmanagedType.LPWStr)]
            public string pwszName;
            public IntPtr pAuthInfo;
            public uint dwReserved2;
        }

        [StructLayout(LayoutKind.Sequential, CharSet=CharSet.Auto)]
        private struct MULTI_QI
        {
            public IntPtr iid;
            [MarshalAs(UnmanagedType.IUnknown)]
            public object pItf;
            public uint hr;
        }

        [StructLayout(LayoutKind.Sequential)]
        private struct SERVERPARAM
        {
            public Guid clsid;
            public string progID;
            public string description;
        }
    }
}

