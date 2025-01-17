
// OPCClientView.h : COPCClientView 类的接口
//


#pragma once


class COPCClientView : public CListView
{
protected: // 仅从序列化创建
	COPCClientView();
	DECLARE_DYNCREATE(COPCClientView)

// 属性
public:
	COPCClientDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~COPCClientView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // OPCClientView.cpp 中的调试版本
inline COPCClientDoc* COPCClientView::GetDocument() const
   { return reinterpret_cast<COPCClientDoc*>(m_pDocument); }
#endif

