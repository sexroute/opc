
// OPCClientView.h : COPCClientView ��Ľӿ�
//


#pragma once


class COPCClientView : public CListView
{
protected: // �������л�����
	COPCClientView();
	DECLARE_DYNCREATE(COPCClientView)

// ����
public:
	COPCClientDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~COPCClientView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // OPCClientView.cpp �еĵ��԰汾
inline COPCClientDoc* COPCClientView::GetDocument() const
   { return reinterpret_cast<COPCClientDoc*>(m_pDocument); }
#endif

