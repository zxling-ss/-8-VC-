
// MFCApplication8.1View.cpp: CMFCApplication81View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication8.1.h"
#endif

#include "MFCApplication8.1Doc.h"
#include "MFCApplication8.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication81View

IMPLEMENT_DYNCREATE(CMFCApplication81View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication81View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication81View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_MBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFCApplication81View 构造/析构

CMFCApplication81View::CMFCApplication81View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication81View::~CMFCApplication81View()
{
}

BOOL CMFCApplication81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication81View 绘图

void CMFCApplication81View::OnDraw(CDC* pDC)
{
	CMFCApplication81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->r);
}


// CMFCApplication81View 打印


void CMFCApplication81View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication81View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication81View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication81View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication81View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication81View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication81View 诊断

#ifdef _DEBUG
void CMFCApplication81View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication81Doc* CMFCApplication81View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication81Doc)));
	return (CMFCApplication81Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication81View 消息处理程序


void CMFCApplication81View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication81Doc* pDoc = GetDocument();
	pDoc->a = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication81View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication81Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if (point.x > pDoc->r.left&& point.x<pDoc->r.right && point.y>pDoc->r.top&& point.y < pDoc->r.bottom && pDoc->time) {
		pDoc->a=pDoc->p.x - 100;
		pDoc->b = pDoc->p.y - 100;
		pDoc->c = 300 - pDoc->p.x;
		pDoc->d = 200 - pDoc->p.y;
		pDoc->r.left = point.x - pDoc->a;
		pDoc->r.top = point.y - pDoc->b;
		pDoc->r.right = point.x - pDoc->c;
		pDoc->r.bottom= point.y - pDoc->d;
		Invalidate();

	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication81View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication81Doc* pDoc = GetDocument();
	pDoc->time = 0;
	pDoc->a = point.x - 100;
	pDoc->b = point.y - 100;
	pDoc->c = 300-point.x ;
	pDoc->d = 200-point.y;
	pDoc->r.left = point.x - pDoc->a;
	pDoc->r.top = point.y - pDoc->b;
	pDoc->r.right = point.x + pDoc->c;
	pDoc->r.bottom= point.y + pDoc->d;
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication81View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication81Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	if (pDoc->a && pDoc->r.right <= cr.right && !pDoc->b)
	{
     pDoc->r.left += 5;
	 pDoc->r.right += 5;
	 Invalidate();
	}
	if (pDoc->r.right >= cr.right)
		pDoc->b = 1;
	if (pDoc->a && pDoc->r.left >= 0 && pDoc->b)
	{
		pDoc->r.left -= 5;
		pDoc->r.right -= 5;
		Invalidate();
	}
	if (pDoc->r.left <= 0)
		pDoc->b = 0;
	CView::OnTimer(nIDEvent);
}


void CMFCApplication81View::OnMButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication81Doc* pDoc = GetDocument();
	pDoc->a = 0;
	CView::OnMButtonDblClk(nFlags, point);
}
