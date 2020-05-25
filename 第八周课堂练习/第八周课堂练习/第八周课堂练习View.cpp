
// �ڰ��ܿ�����ϰView.cpp : C�ڰ��ܿ�����ϰView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ��ܿ�����ϰ.h"
#endif

#include "�ڰ��ܿ�����ϰDoc.h"
#include "�ڰ��ܿ�����ϰView.h"
#include "fileDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڰ��ܿ�����ϰView

IMPLEMENT_DYNCREATE(C�ڰ��ܿ�����ϰView, CView)

BEGIN_MESSAGE_MAP(C�ڰ��ܿ�����ϰView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32771, &C�ڰ��ܿ�����ϰView::On32771)
END_MESSAGE_MAP()

// C�ڰ��ܿ�����ϰView ����/����

C�ڰ��ܿ�����ϰView::C�ڰ��ܿ�����ϰView()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڰ��ܿ�����ϰView::~C�ڰ��ܿ�����ϰView()
{
}

BOOL C�ڰ��ܿ�����ϰView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڰ��ܿ�����ϰView ����

void C�ڰ��ܿ�����ϰView::OnDraw(CDC* /*pDC*/)
{
	C�ڰ��ܿ�����ϰDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڰ��ܿ�����ϰView ��ӡ

BOOL C�ڰ��ܿ�����ϰView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڰ��ܿ�����ϰView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڰ��ܿ�����ϰView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڰ��ܿ�����ϰView ���

#ifdef _DEBUG
void C�ڰ��ܿ�����ϰView::AssertValid() const
{
	CView::AssertValid();
}

void C�ڰ��ܿ�����ϰView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڰ��ܿ�����ϰDoc* C�ڰ��ܿ�����ϰView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڰ��ܿ�����ϰDoc)));
	return (C�ڰ��ܿ�����ϰDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ڰ��ܿ�����ϰView ��Ϣ�������

// (1)��˫�����������������ļ��Ի��򣬴���ѡ����һ���ļ������ڿͻ�����ʾ���ļ�����
void C�ڰ��ܿ�����ϰView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CFileDialog file(TRUE, NULL, NULL, NULL, NULL, NULL);

	if (IDOK == file.DoModal()) {
		CString filePath = file.GetPathName();

		dc.TextOutW(100, 100, filePath);
		filename = filePath;
	}

	CView::OnLButtonDblClk(nFlags, point);
}

//  (2) ��Ȼ����ĳ���˵�������һ���Ի���ʹ���ļ����ڶԻ����е�һ���༭�ؼ�����ʾ������
void C�ڰ��ܿ�����ϰView::On32771()
{
	// TODO: �ڴ���������������
	fileDialog file;
	file.m_filename = filename;
	/*file.m_listfile = filename;*/
	
	UpdateData(false);

	if (IDOK == file.DoModal()) {
		
		
		
	//	UpdateData(true);
	}
	
	
}
