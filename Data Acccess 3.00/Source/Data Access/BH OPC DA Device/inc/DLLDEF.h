#ifndef __DLLDEF__HH__
#define __DLLDEF__HH__


#define _APP_LIB_	__declspec(dllimport)

class DllInstanceSwitcher
{
public:
    DllInstanceSwitcher(CString module)
    {
        m_hInst = AfxGetInstanceHandle();
#ifdef _AFXDLL
		m_hDLL=AfxLoadLibrary(module);
		AfxSetResourceHandle(m_hDLL);
#endif

    }
    void Restore(){
    	AfxSetResourceHandle(m_hInst);
    }
    ~DllInstanceSwitcher()
    {
        AfxSetResourceHandle(m_hInst);
    }

public:
		HINSTANCE m_hDLL;
    HINSTANCE m_hInst;
};
#define _PO_LOG_MSG_		9999
//×ÊÔ´ÇÐ»»
#ifdef _AFXDLL
#define SWITCH_RESOURCE(x) DllInstanceSwitcher __SwitchInstance(x)
#define UN_SWITCH_RESOURCE __SwitchInstance.Restore()
#else
#define SWITCH_RESOURCE(x) 
#define UN_SWITCH_RESOURCE 
#endif

#endif