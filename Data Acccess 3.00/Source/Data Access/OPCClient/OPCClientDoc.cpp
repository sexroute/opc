
// OPCClientDoc.cpp : COPCClientDoc 类的实现
//

#include "stdafx.h"
#include "OPCClient.h"

#include "OPCClientDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COPCClientDoc

IMPLEMENT_DYNCREATE(COPCClientDoc, CDocument)

BEGIN_MESSAGE_MAP(COPCClientDoc, CDocument)
END_MESSAGE_MAP()


// COPCClientDoc 构造/析构

COPCClientDoc::COPCClientDoc()
{
	// TODO: 在此添加一次性构造代码

}

COPCClientDoc::~COPCClientDoc()
{
}

BOOL COPCClientDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// COPCClientDoc 序列化

void COPCClientDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// COPCClientDoc 诊断

#ifdef _DEBUG
void COPCClientDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COPCClientDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COPCClientDoc 命令
