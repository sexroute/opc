
// OPCClientDoc.cpp : COPCClientDoc ���ʵ��
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


// COPCClientDoc ����/����

COPCClientDoc::COPCClientDoc()
{
	// TODO: �ڴ����һ���Թ������

}

COPCClientDoc::~COPCClientDoc()
{
}

BOOL COPCClientDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// COPCClientDoc ���л�

void COPCClientDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// COPCClientDoc ���

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


// COPCClientDoc ����
