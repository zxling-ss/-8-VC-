
// �ڰ��ܿ�����ϰView.h : C�ڰ��ܿ�����ϰView ��Ľӿ�
//

#pragma once


class C�ڰ��ܿ�����ϰView : public CView
{
protected: // �������л�����
	C�ڰ��ܿ�����ϰView();
	DECLARE_DYNCREATE(C�ڰ��ܿ�����ϰView)

// ����
public:
	C�ڰ��ܿ�����ϰDoc* GetDocument() const;

// ����
public:
	CString filename;			//�ļ�����
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�ڰ��ܿ�����ϰView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void On32771();
};

#ifndef _DEBUG  // �ڰ��ܿ�����ϰView.cpp �еĵ��԰汾
inline C�ڰ��ܿ�����ϰDoc* C�ڰ��ܿ�����ϰView::GetDocument() const
   { return reinterpret_cast<C�ڰ��ܿ�����ϰDoc*>(m_pDocument); }
#endif

