﻿
// MFCApplication8.2View.cpp: CMFCApplication82View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication8.2.h"
#include"MyDlg0.h"
#endif

#include "MFCApplication8.2Doc.h"
#include "MFCApplication8.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication82View

IMPLEMENT_DYNCREATE(CMFCApplication82View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication82View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication82View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32771, &CMFCApplication82View::On32771)
END_MESSAGE_MAP()

// CMFCApplication82View 构造/析构

CMFCApplication82View::CMFCApplication82View() noexcept
{
	// TODO: 在此处添加构造代码
	
}

CMFCApplication82View::~CMFCApplication82View()
{
	
}

BOOL CMFCApplication82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication82View 绘图

void CMFCApplication82View::OnDraw(CDC* pDC)
{
	CMFCApplication82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication82View 打印


void CMFCApplication82View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication82View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication82View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication82View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication82View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication82View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication82View 诊断

#ifdef _DEBUG
void CMFCApplication82View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication82Doc* CMFCApplication82View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication82Doc)));
	return (CMFCApplication82Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication82View 消息处理程序


void CMFCApplication82View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MyDlg0* pD = new MyDlg0;
	pD->Create(ID_32771);
	pD->ShowWindow(1);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCApplication82View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int X, Y, Z;
		Z = dlg.z;
		X = dlg.x;
		Y = dlg.y;
	}
}
