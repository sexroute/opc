
// OPCClientView.cpp : COPCClientView 类的实现
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

// COPCClientView 构造/析构

COPCClientView::COPCClientView()
{
	// TODO: 在此处添加构造代码

}

COPCClientView::~COPCClientView()
{
}

BOOL COPCClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CListView::PreCreateWindow(cs);
}

void COPCClientView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

 

	CListCtrl     &m_list   =   GetListCtrl();           

	m_list.SetBkColor(RGB(242,251,255));	
	m_list.SetTextColor(   RGB(12,26,234)   ); 

	m_list.InsertColumn(0   ,   "OPC测点名",         LVCFMT_LEFT,   80,     0   ); 
	m_list.InsertColumn(1   ,   "状态监测测点名",             LVCFMT_LEFT,   100,     1   ); 
	m_list.InsertColumn(2   ,   "公司ID",         LVCFMT_LEFT,   100,     2   ); 
	m_list.InsertColumn(3   ,   "分厂ID",             LVCFMT_LEFT,   100,   3   ); 
	m_list.InsertColumn(4   ,   "设备ID",             LVCFMT_LEFT,   100,     4   ); 
	m_list.InsertColumn(5   ,   "当前值",         LVCFMT_LEFT,   100,     5   ); 
	m_list.InsertColumn(6   ,   "上次更新时间",         LVCFMT_LEFT,   100,     6   ); 
	m_list.InsertColumn(7   ,   "测点值更新状态",             LVCFMT_LEFT,   100,   7   ); 
	m_list.InsertColumn(8   ,   "上次发送时间",             LVCFMT_LEFT,   100,     8   ); 
	m_list.InsertColumn(9   ,   "读取模式",         LVCFMT_LEFT,   100,       9); 
	m_list.ModifyStyle(   LVS_TYPEMASK,LVS_REPORT   |   LVS_SINGLESEL   ); 
	m_list.SetExtendedStyle(     LVS_EX_FULLROWSELECT   |   LVS_EX_GRIDLINES   |LVS_EX_HEADERDRAGDROP   |   LVS_EX_ONECLICKACTIVATE     ); 


	// TODO: 调用 GetListCtrl() 直接访问 ListView 的列表控件，
	//  从而可以用项填充 ListView。
}


// COPCClientView 诊断

#ifdef _DEBUG
void COPCClientView::AssertValid() const
{
	CListView::AssertValid();
}

void COPCClientView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

COPCClientDoc* COPCClientView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COPCClientDoc)));
	return (COPCClientDoc*)m_pDocument;
}
#endif //_DEBUG


// COPCClientView 消息处理程序
