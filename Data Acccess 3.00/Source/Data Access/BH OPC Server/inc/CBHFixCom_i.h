

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Apr 17 11:16:40 2012
 */
/* Compiler settings for CBHFixCom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CBHFixCom_i_h__
#define __CBHFixCom_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICBHFixComImp_FWD_DEFINED__
#define __ICBHFixComImp_FWD_DEFINED__
typedef interface ICBHFixComImp ICBHFixComImp;
#endif 	/* __ICBHFixComImp_FWD_DEFINED__ */


#ifndef __CBHFixComImp_FWD_DEFINED__
#define __CBHFixComImp_FWD_DEFINED__

#ifdef __cplusplus
typedef class CBHFixComImp CBHFixComImp;
#else
typedef struct CBHFixComImp CBHFixComImp;
#endif /* __cplusplus */

#endif 	/* __CBHFixComImp_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICBHFixComImp_INTERFACE_DEFINED__
#define __ICBHFixComImp_INTERFACE_DEFINED__

/* interface ICBHFixComImp */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICBHFixComImp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00AD95BB-643F-45C8-8A86-14518AEBCCDD")
    ICBHFixComImp : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDouble( 
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ DOUBLE *apDblRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLong( 
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ LONG *aplRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ BSTR *apBstrRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetItem( 
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ BSTR *apbstrVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTime( 
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ BSTR *apBstrDate) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetItemBuf( 
            /* [in] */ LONG anFixCode,
            /* [in] */ LONG anSize,
            /* [retval][out] */ VARIANT *apDataBuf) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetItemBuf( 
            /* [in] */ LONG nFixCode,
            /* [in] */ LONG nSize,
            /* [in] */ VARIANT *apDataBuffer,
            /* [retval][out] */ LONG *aplRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetItemDouble( 
            /* [in] */ LONG anFixCode,
            /* [in] */ double adblValue,
            /* [retval][out] */ LONG *aplRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetItem( 
            /* [in] */ LONG anFixCode,
            /* [in] */ LONG alValue,
            /* [retval][out] */ LONG *aplRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetItemString( 
            LONG anFixCode,
            BSTR *abstrDataVal,
            /* [retval][out] */ LONG *aplRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateAnswer( 
            /* [in] */ LONG anFixCode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateAnswerMul( 
            /* [in] */ LONG anFunc) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateNextAnswer( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateEndMak( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAco( 
            /* [retval][out] */ LONG *apLRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAci( 
            /* [retval][out] */ LONG *aplACIData) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ LONG alACI) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCommType( 
            LONG *apTypeRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetBusy( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetIdle( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsIdle( 
            /* [retval][out] */ LONG *apIsIdle) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateHead( 
            /* [in] */ LONG anFunc) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCommType( 
            LONG anTypeRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Link( 
            /* [in] */ BSTR *pszDest,
            /* [in] */ BSTR *pszDept,
            /* [retval][out] */ LONG *abLinked) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE More( 
            /* [retval][out] */ LONG *apRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICBHFixComImpVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICBHFixComImp * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICBHFixComImp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICBHFixComImp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICBHFixComImp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICBHFixComImp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICBHFixComImp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICBHFixComImp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetDouble )( 
            ICBHFixComImp * This,
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ DOUBLE *apDblRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLong )( 
            ICBHFixComImp * This,
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ LONG *aplRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Get )( 
            ICBHFixComImp * This,
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ BSTR *apBstrRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            ICBHFixComImp * This,
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ BSTR *apbstrVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTime )( 
            ICBHFixComImp * This,
            /* [in] */ LONG nFixCode,
            /* [retval][out] */ BSTR *apBstrDate);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItemBuf )( 
            ICBHFixComImp * This,
            /* [in] */ LONG anFixCode,
            /* [in] */ LONG anSize,
            /* [retval][out] */ VARIANT *apDataBuf);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItemBuf )( 
            ICBHFixComImp * This,
            /* [in] */ LONG nFixCode,
            /* [in] */ LONG nSize,
            /* [in] */ VARIANT *apDataBuffer,
            /* [retval][out] */ LONG *aplRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItemDouble )( 
            ICBHFixComImp * This,
            /* [in] */ LONG anFixCode,
            /* [in] */ double adblValue,
            /* [retval][out] */ LONG *aplRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItem )( 
            ICBHFixComImp * This,
            /* [in] */ LONG anFixCode,
            /* [in] */ LONG alValue,
            /* [retval][out] */ LONG *aplRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItemString )( 
            ICBHFixComImp * This,
            LONG anFixCode,
            BSTR *abstrDataVal,
            /* [retval][out] */ LONG *aplRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateAnswer )( 
            ICBHFixComImp * This,
            /* [in] */ LONG anFixCode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateAnswerMul )( 
            ICBHFixComImp * This,
            /* [in] */ LONG anFunc);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateNextAnswer )( 
            ICBHFixComImp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateEndMak )( 
            ICBHFixComImp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAco )( 
            ICBHFixComImp * This,
            /* [retval][out] */ LONG *apLRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAci )( 
            ICBHFixComImp * This,
            /* [retval][out] */ LONG *aplACIData);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ICBHFixComImp * This,
            /* [in] */ LONG alACI);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCommType )( 
            ICBHFixComImp * This,
            LONG *apTypeRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetBusy )( 
            ICBHFixComImp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetIdle )( 
            ICBHFixComImp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsIdle )( 
            ICBHFixComImp * This,
            /* [retval][out] */ LONG *apIsIdle);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateHead )( 
            ICBHFixComImp * This,
            /* [in] */ LONG anFunc);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCommType )( 
            ICBHFixComImp * This,
            LONG anTypeRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Link )( 
            ICBHFixComImp * This,
            /* [in] */ BSTR *pszDest,
            /* [in] */ BSTR *pszDept,
            /* [retval][out] */ LONG *abLinked);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *More )( 
            ICBHFixComImp * This,
            /* [retval][out] */ LONG *apRetVal);
        
        END_INTERFACE
    } ICBHFixComImpVtbl;

    interface ICBHFixComImp
    {
        CONST_VTBL struct ICBHFixComImpVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICBHFixComImp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICBHFixComImp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICBHFixComImp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICBHFixComImp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICBHFixComImp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICBHFixComImp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICBHFixComImp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICBHFixComImp_GetDouble(This,nFixCode,apDblRetVal)	\
    ( (This)->lpVtbl -> GetDouble(This,nFixCode,apDblRetVal) ) 

#define ICBHFixComImp_GetLong(This,nFixCode,aplRetVal)	\
    ( (This)->lpVtbl -> GetLong(This,nFixCode,aplRetVal) ) 

#define ICBHFixComImp_Get(This,nFixCode,apBstrRetVal)	\
    ( (This)->lpVtbl -> Get(This,nFixCode,apBstrRetVal) ) 

#define ICBHFixComImp_GetItem(This,nFixCode,apbstrVal)	\
    ( (This)->lpVtbl -> GetItem(This,nFixCode,apbstrVal) ) 

#define ICBHFixComImp_GetTime(This,nFixCode,apBstrDate)	\
    ( (This)->lpVtbl -> GetTime(This,nFixCode,apBstrDate) ) 

#define ICBHFixComImp_GetItemBuf(This,anFixCode,anSize,apDataBuf)	\
    ( (This)->lpVtbl -> GetItemBuf(This,anFixCode,anSize,apDataBuf) ) 

#define ICBHFixComImp_SetItemBuf(This,nFixCode,nSize,apDataBuffer,aplRetVal)	\
    ( (This)->lpVtbl -> SetItemBuf(This,nFixCode,nSize,apDataBuffer,aplRetVal) ) 

#define ICBHFixComImp_SetItemDouble(This,anFixCode,adblValue,aplRetVal)	\
    ( (This)->lpVtbl -> SetItemDouble(This,anFixCode,adblValue,aplRetVal) ) 

#define ICBHFixComImp_SetItem(This,anFixCode,alValue,aplRetVal)	\
    ( (This)->lpVtbl -> SetItem(This,anFixCode,alValue,aplRetVal) ) 

#define ICBHFixComImp_SetItemString(This,anFixCode,abstrDataVal,aplRetVal)	\
    ( (This)->lpVtbl -> SetItemString(This,anFixCode,abstrDataVal,aplRetVal) ) 

#define ICBHFixComImp_CreateAnswer(This,anFixCode)	\
    ( (This)->lpVtbl -> CreateAnswer(This,anFixCode) ) 

#define ICBHFixComImp_CreateAnswerMul(This,anFunc)	\
    ( (This)->lpVtbl -> CreateAnswerMul(This,anFunc) ) 

#define ICBHFixComImp_CreateNextAnswer(This)	\
    ( (This)->lpVtbl -> CreateNextAnswer(This) ) 

#define ICBHFixComImp_CreateEndMak(This)	\
    ( (This)->lpVtbl -> CreateEndMak(This) ) 

#define ICBHFixComImp_GetAco(This,apLRetVal)	\
    ( (This)->lpVtbl -> GetAco(This,apLRetVal) ) 

#define ICBHFixComImp_GetAci(This,aplACIData)	\
    ( (This)->lpVtbl -> GetAci(This,aplACIData) ) 

#define ICBHFixComImp_Write(This,alACI)	\
    ( (This)->lpVtbl -> Write(This,alACI) ) 

#define ICBHFixComImp_GetCommType(This,apTypeRetVal)	\
    ( (This)->lpVtbl -> GetCommType(This,apTypeRetVal) ) 

#define ICBHFixComImp_SetBusy(This)	\
    ( (This)->lpVtbl -> SetBusy(This) ) 

#define ICBHFixComImp_SetIdle(This)	\
    ( (This)->lpVtbl -> SetIdle(This) ) 

#define ICBHFixComImp_IsIdle(This,apIsIdle)	\
    ( (This)->lpVtbl -> IsIdle(This,apIsIdle) ) 

#define ICBHFixComImp_CreateHead(This,anFunc)	\
    ( (This)->lpVtbl -> CreateHead(This,anFunc) ) 

#define ICBHFixComImp_SetCommType(This,anTypeRetVal)	\
    ( (This)->lpVtbl -> SetCommType(This,anTypeRetVal) ) 

#define ICBHFixComImp_Link(This,pszDest,pszDept,abLinked)	\
    ( (This)->lpVtbl -> Link(This,pszDest,pszDept,abLinked) ) 

#define ICBHFixComImp_More(This,apRetVal)	\
    ( (This)->lpVtbl -> More(This,apRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICBHFixComImp_INTERFACE_DEFINED__ */



#ifndef __CBHFixComLib_LIBRARY_DEFINED__
#define __CBHFixComLib_LIBRARY_DEFINED__

/* library CBHFixComLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_CBHFixComLib;

EXTERN_C const CLSID CLSID_CBHFixComImp;

#ifdef __cplusplus

class DECLSPEC_UUID("30A2C9F4-11E0-4DA5-A1FD-B2D8E65E31B2")
CBHFixComImp;
#endif
#endif /* __CBHFixComLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


