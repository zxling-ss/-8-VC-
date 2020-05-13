
// MFCApplication6View.cpp : CMFCApplication6View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication6.h"
#endif

#include "MFCApplication6Doc.h"
#include "MFCApplication6View.h"
#include "MyDlg0.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6View

IMPLEMENT_DYNCREATE(CMFCApplication6View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication6View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32771, &CMFCApplication6View::On32771)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MBUTTONDOWN()
	ON_COMMAND(ID_32772, &CMFCApplication6View::On32772)
END_MESSAGE_MAP()

// CMFCApplication6View ����/����

CMFCApplication6View::CMFCApplication6View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication6View::~CMFCApplication6View()
{
}

BOOL CMFCApplication6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6View ����

void CMFCApplication6View::OnDraw(CDC* pDC)
{
	CMFCApplication6Doc* pDoc = GetDocument();
	
	
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	//(3) �����ѡ����Բ��ͨ������Բ�������߻�һ�����о�������ʾѡ��״̬��
	//left��top�ֱ��ʾ�������ϽǶ���ĺ�����������꣬right��bottom�ֱ��ʾ�������½Ƕ���ĺ������������
	//������м�ѡ����Բ��ʱ��
	if (pDoc->Select_elliptical) {
		CDC * dc = GetDC();
		CPen * pOldPen = NULL;
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 255, 0));//����
		pOldPen = dc->SelectObject(&pen);
		CBrush * pOldBrush = NULL;
		CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//����͸��Ч��
		pOldBrush = dc->SelectObject(pBrush);



		dc->Rectangle(pDoc->re);				//���ƾ���
		dc->SelectObject(pOldPen);				//�ָ�ԭʼ�Ļ���
		dc->SelectObject(pOldBrush);			//�ָ���ˢ
		pen.DeleteObject();




		////�����»���
		//CPen newPen(PS_DASH, 1, RGB(0, 255, 0));
		////�����»��ʲ��Ѿɻ��ʲ��Ѿɻ��ʴ���ָ����
		//CPen *oldPen = pDC->SelectObject(&newPen);

		//dc1.Rectangle(pDoc->re);
		////if((point.x>=(pDoc->re.left))&&(point.x<= (pDoc->re.right))&& (point.y >= (pDoc->re.top))&&(point.y <= (pDoc->re.bottom)))
		////pDC->Rectangle(pDoc->re);			//���»��ƾ���
		//
		////ʹ���»��ʻ�������֮�󣬻ָ�ԭ����
		//dc2.Ellipse(pDoc->re);
		////pDC->Ellipse(pDoc ->re);				//������Բͼ��

		// pOldBrush = NULL;
		////��ÿջ�ˢָ�룬����FromHandle������ɾ����ָ���ת��
		// pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(BLACK_BRUSH));
		////�ջ�ˢ�����豸������
		//pOldBrush = dc->SelectObject(pBrush);

		//�����»�ˢ
		//CBrush newBrush(RGB(0, 255, 255)); //������ɫ
		CBrush newBrush(RGB(pDoc->Rvalue,pDoc->Gvalue, pDoc->Bvalue)); //������ɫ
		CBrush *oldBrush = pDC->SelectObject(&newBrush);

		pDC->Ellipse(pDoc->re);				//������Բͼ��
		//pDC->FillRect(&pBrush);
		//��ʹ���»�ˢ��������֮�󣬻ָ�ԭ��ˢ
		pDC->SelectObject(oldBrush);
		////pDC->Ellipse(100, 100, 100, 100);

		//���½���û��ѡ�е�״̬
		pDoc->Select_elliptical = false;
	}
	else {
		
		
		pDC->Ellipse(pDoc->re);				//������Բͼ��
	}
}


// CMFCApplication6View ��ӡ


void CMFCApplication6View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CMFCApplication6View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication6View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication6View ���

#ifdef _DEBUG
void CMFCApplication6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6Doc* CMFCApplication6View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6Doc)));
	return (CMFCApplication6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6View ��Ϣ�������

//�ڿͻ���������ϳ���Բ������ʾ�ϳ�ʱ�Ľ���Ч����
void CMFCApplication6View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication6Doc* pDoc = GetDocument();
	pDoc ->re.left = point.x;
	pDoc->re.top = point.y;
	pDoc -> a = 1;
		

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication6View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication6Doc* pDoc = GetDocument();
	pDoc->re.right = point.x;
	pDoc ->re.bottom = point.y;
	pDoc->a = 0;
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication6View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication6Doc* pDoc = GetDocument();
	if (pDoc->a) 
	{
		pDoc->re.right = point.x;
		pDoc->re.bottom = point.y;
		Invalidate();

		CView::OnMouseMove(nFlags, point);
	}
}


//(2)  ͨ������˵��������Ի���Ȼ���ڶԻ���������ȷ����Բ�����ݣ����ݴ������ڿͻ����л���Բ��
void CMFCApplication6View::On32771()
{
	// TODO: �ڴ���������������
	MyDlg0 dlg;
	int t = dlg.DoModal();
	CMFCApplication6Doc* pDoc = GetDocument();
	if (t == IDOK)
	{
		
		
		//left��top�ֱ��ʾ�������ϽǶ���ĺ�����������꣬right��bottom�ֱ��ʾ�������½Ƕ���ĺ������������
		pDoc->re.left = dlg.TopRx;
		pDoc->re.top = dlg.TopRy;
		pDoc->re.right = dlg.LowerLx;
		pDoc->re.bottom = dlg.LowerLy;
		Invalidate();
		//dc.Ellipse(rect);
	}

}


void CMFCApplication6View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	

	CView::OnLButtonDblClk(nFlags, point);
}

//����м����¼��������
void CMFCApplication6View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication6Doc* pDoc = GetDocument();
	
	pDoc->Select_elliptical= true;

	Invalidate();
	CView::OnMButtonDown(nFlags, point);
}


void CMFCApplication6View::On32772()
{
	// TODO: �ڴ���������������
	MyDlg1 dlg;
	CMFCApplication6Doc* pDoc = GetDocument();
	int t = dlg.DoModal();
	if (t == IDOK){
		
		pDoc->Rvalue = dlg.RedValue;
		pDoc->Gvalue = dlg.GreenValue;
		pDoc->Bvalue = dlg.BlueValue;

	}
}
