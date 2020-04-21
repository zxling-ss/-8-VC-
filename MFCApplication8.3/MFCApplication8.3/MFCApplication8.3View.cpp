
// MFCApplication8.3View.cpp: CMFCApplication83View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication8.3.h"
#endif

#include "MFCApplication8.3Doc.h"
#include "MFCApplication8.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication83View

IMPLEMENT_DYNCREATE(CMFCApplication83View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication83View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication83View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFCApplication83View 构造/析构

CMFCApplication83View::CMFCApplication83View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication83View::~CMFCApplication83View()
{
}

BOOL CMFCApplication83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication83View 绘图

void CMFCApplication83View::OnDraw(CDC* pDC)
{
	CMFCApplication83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	GetClientRect(&cr);
	pDoc->re.top = cr.bottom / 2 - 50;
	pDoc->re.bottom = cr.bottom / 2 + 50;
	pDC->Ellipse(pDoc->re);
	if (pDoc->set) {
		SetTimer(0, 100, NULL);
	}

}


// CMFCApplication83View 打印


void CMFCApplication83View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication83View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication83View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication83View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication83View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication83View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication83View 诊断

#ifdef _DEBUG
void CMFCApplication83View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication83Doc* CMFCApplication83View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication83Doc)));
	return (CMFCApplication83Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication83View 消息处理程序


void CMFCApplication83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication83Doc* pDoc = GetDocument();
	pDoc->a = 1;


	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication83View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication83Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	if (pDoc->a && pDoc->re.right <= cr.right && !pDoc->b) {
		pDoc->re.left += 5; pDoc->re.right += 5;
		Invalidate();
		if (pDoc->re.right >= cr.right) pDoc->b = 1;
		if (pDoc->a && pDoc->re.left>= 0 & pDoc->b) {
			pDoc->re.left -= 5; pDoc->re.right -= 5;
			Invalidate();
			if (pDoc->re.left <= 0) pDoc->b = 0;
		}
	}
	CView::OnTimer(nIDEvent);
}




void CMFCApplication83View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication83Doc* pDoc = GetDocument();
	pDoc -> a=0;

	CView::OnLButtonDblClk(nFlags, point);
}
