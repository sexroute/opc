
// OPCClientView.cpp : COPCClientView ���ʵ��
//

#include "stdafx.h"
#include "OPCClient.h"

#include "OPCClientDoc.h"
#include "OPCClientView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COPCClientView

IMPLEMENT_DYNCREATE(COPCClientView, CListView)

BEGIN_MESSAGE_MAP(COPCClientView, CListView)
END_MESSAGE_MAP()

// COPCClientView ����/����

COPCClientView::COPCClientView()
{
	// TODO: �ڴ˴���ӹ������

}

COPCClientView::~COPCClientView()
{
}

BOOL COPCClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CListView::PreCreateWindow(cs);
}

void COPCClientView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

 

	CListCtrl     &m_list   =   GetListCtrl();           

	m_list.SetBkColor(RGB(242,251,255));	
	m_list.SetTextColor(   RGB(12,26,234)   ); 

	m_list.InsertColumn(0   ,   "OPC�����",         LVCFMT_LEFT,   80,     0   ); 
	m_list.InsertColumn(1   ,   "״̬�������",             LVCFMT_LEFT,   100,     1   ); 
	m_list.InsertColumn(2   ,   "��˾ID",         LVCFMT_LEFT,   100,     2   ); 
	m_list.InsertColumn(3   ,   "�ֳ�ID",             LVCFMT_LEFT,   100,   3   ); 
	m_list.InsertColumn(4   ,   "�豸ID",             LVCFMT_LEFT,   100,     4   ); 
	m_list.InsertColumn(5   ,   "��ǰֵ",         LVCFMT_LEFT,   100,     5   ); 
	m_list.InsertColumn(6   ,   "�ϴθ���ʱ��",         LVCFMT_LEFT,   100,     6   ); 
	m_list.InsertColumn(7   ,   "���ֵ����״̬",             LVCFMT_LEFT,   100,   7   ); 
	m_list.InsertColumn(8   ,   "�ϴη���ʱ��",             LVCFMT_LEFT,   100,     8   ); 
	m_list.InsertColumn(9   ,   "��ȡģʽ",         LVCFMT_LEFT,   100,       9); 
	m_list.ModifyStyle(   LVS_TYPEMASK,LVS_REPORT   |   LVS_SINGLESEL   ); 
	m_list.SetExtendedStyle(     LVS_EX_FULLROWSELECT   |   LVS_EX_GRIDLINES   |LVS_EX_HEADERDRAGDROP   |   LVS_EX_ONECLICKACTIVATE     ); 


	// TODO: ���� GetListCtrl() ֱ�ӷ��� ListView ���б�ؼ���
	//  �Ӷ������������ ListView��
}


// COPCClientView ���

#ifdef _DEBUG
void COPCClientView::AssertValid() const
{
	CListView::AssertValid();
}

void COPCClientView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

COPCClientDoc* COPCClientView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COPCClientDoc)));
	return (COPCClientDoc*)m_pDocument;
}
#endif //_DEBUG


// COPCClientView ��Ϣ�������
