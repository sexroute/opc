// CBHFixComImp.h : CCBHFixComImp 的声明

#pragma once
#include "resource.h"       // 主符号

#include "..\inc\fixcommex.h"



#include "CBHFixCom_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CCBHFixComImp

class ATL_NO_VTABLE CCBHFixComImp :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCBHFixComImp, &CLSID_CBHFixComImp>,
	public IDispatchImpl<ICBHFixComImp, &IID_ICBHFixComImp, &LIBID_CBHFixComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCBHFixComImp()
	{
		this->m_pFixCom = new CFixCommEx(true,EN_FIXCOMM_TYPE_MFC);
		this->m_pFixComA = new CFixCommEx(true,EN_FIXCOMM_TYPE_ACE);
		this->m_nFixCommType = EN_FIXCOMM_TYPE_ACE;
	}

	virtual ~CCBHFixComImp()
	{
		if (NULL!= this->m_pFixCom)
		{
			try
			{
				this->m_pFixCom->Close();

			}catch(...)
			{
				
			}
			delete this->m_pFixCom;
			this->m_pFixCom = NULL;
		}

		if (NULL!= this->m_pFixComA)
		{
			try
			{
				this->m_pFixComA->Close();

			}catch(...)
			{

			}
			delete this->m_pFixComA;
			this->m_pFixComA = NULL;
		}

	}
DECLARE_REGISTRY_RESOURCEID(IDR_CBHFIXCOMIMP)


BEGIN_COM_MAP(CCBHFixComImp)
	COM_INTERFACE_ENTRY(ICBHFixComImp)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

private:
	CFixCommEx  * m_pFixComA;
	CFixCommEx * m_pFixCom;
	int m_nFixCommType;
	CFixCommEx & GetInternalFixCom();
	HRESULT CheckSafeArray(					VARIANT * apVariant,
											SAFEARRAY * & arefApData,
											LONG & anUBoundSize,
											LONG & anLBoundSize);
public:
	STDMETHOD(GetDouble)(LONG nFixCode, DOUBLE* apDblRetVal);
	STDMETHOD(GetLong)(LONG nFixCode, LONG* aplRetVal);
	STDMETHOD(Get)(LONG nFixCode, BSTR* apBstrRetVal);
	STDMETHOD(GetItem)(LONG nFixCode, BSTR* apbstrVal);
	STDMETHOD(GetTime)(LONG nFixCode, BSTR* apBstrDate);
	STDMETHOD(GetItemBuf)(LONG anFixCode, LONG anSize, VARIANT* apDataBuf);
	STDMETHOD(SetItemBuf)(	LONG nFixCode, 
							LONG nSize, VARIANT* apDataBuffer,LONG * aplRetVal);
	STDMETHOD(SetItemDouble)(LONG anFixCode, double adblValue,LONG * aplRetVal);
	STDMETHOD(SetItem)(LONG anFixCode, LONG alValue,LONG * aplRetVal);
	STDMETHOD(SetItemString)(LONG anFixCode, BSTR * abstrDataVa,LONG * aplRetVall);
	STDMETHOD(CreateAnswer)(LONG anFixCode);
	STDMETHOD(CreateAnswerMul)(LONG anFunc);
	STDMETHOD(CreateNextAnswer)(void);
	STDMETHOD(CreateEndMak)(void);
	STDMETHOD(GetAco)(LONG* apLRetVal);
	STDMETHOD(GetAci)(LONG* aplACIData);
	STDMETHOD(Write)(LONG alACI);
	STDMETHOD(More)(LONG* aplMoreData);
	STDMETHOD(SetCommType)(LONG anCommType);
	STDMETHOD(GetCommType)(LONG* apTypeRetVal);
	STDMETHOD(SetBusy)(void);
	STDMETHOD(SetIdle)(void);


	STDMETHOD(IsIdle)(LONG* apIsIdle);
	STDMETHOD(CreateHead)(LONG anFunc);

	STDMETHOD(Link)(BSTR * pszDest, BSTR  *pszDept, LONG* abLinked);
};

OBJECT_ENTRY_AUTO(__uuidof(CBHFixComImp), CCBHFixComImp)
