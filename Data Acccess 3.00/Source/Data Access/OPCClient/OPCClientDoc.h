
// OPCClientDoc.h : COPCClientDoc ��Ľӿ�
//


#pragma once


class COPCClientDoc : public CDocument
{
protected: // �������л�����
	COPCClientDoc();
	DECLARE_DYNCREATE(COPCClientDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~COPCClientDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


