
// MFCApplication6View.cpp : CMFCApplication6View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CMFCApplication6View 构造/析构

CMFCApplication6View::CMFCApplication6View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication6View::~CMFCApplication6View()
{
}

BOOL CMFCApplication6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6View 绘制

void CMFCApplication6View::OnDraw(CDC* pDC)
{
	CMFCApplication6Doc* pDoc = GetDocument();
	
	
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	//(3) 用鼠标选择椭圆，通过在椭圆外用虚线画一个外切矩形来表示选中状态；
	//left、top分别表示矩形左上角顶点的横坐标和纵坐标，right、bottom分别表示矩形右下角顶点的横坐标和纵坐标
	//当鼠标中键选择椭圆的时候
	if (pDoc->Select_elliptical) {
		CDC * dc = GetDC();
		CPen * pOldPen = NULL;
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 255, 0));//虚线
		pOldPen = dc->SelectObject(&pen);
		CBrush * pOldBrush = NULL;
		CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//背景透明效果
		pOldBrush = dc->SelectObject(pBrush);



		dc->Rectangle(pDoc->re);				//绘制矩形
		dc->SelectObject(pOldPen);				//恢复原始的画笔
		dc->SelectObject(pOldBrush);			//恢复画刷
		pen.DeleteObject();




		////创建新画笔
		//CPen newPen(PS_DASH, 1, RGB(0, 255, 0));
		////载入新画笔并把旧画笔并把旧画笔存入指针中
		//CPen *oldPen = pDC->SelectObject(&newPen);

		//dc1.Rectangle(pDoc->re);
		////if((point.x>=(pDoc->re.left))&&(point.x<= (pDoc->re.right))&& (point.y >= (pDoc->re.top))&&(point.y <= (pDoc->re.bottom)))
		////pDC->Rectangle(pDoc->re);			//重新绘制矩形
		//
		////使用新画笔绘制线条之后，恢复原画笔
		//dc2.Ellipse(pDoc->re);
		////pDC->Ellipse(pDoc ->re);				//绘制椭圆图形

		// pOldBrush = NULL;
		////获得空画刷指针，利用FromHandle函数完成句柄和指针的转换
		// pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(BLACK_BRUSH));
		////空画刷载入设备描述表
		//pOldBrush = dc->SelectObject(pBrush);

		//创建新画刷
		//CBrush newBrush(RGB(0, 255, 255)); //更改颜色
		CBrush newBrush(RGB(pDoc->Rvalue,pDoc->Gvalue, pDoc->Bvalue)); //更改颜色
		CBrush *oldBrush = pDC->SelectObject(&newBrush);

		pDC->Ellipse(pDoc->re);				//绘制椭圆图形
		//pDC->FillRect(&pBrush);
		//在使用新画刷绘制线条之后，恢复原画刷
		pDC->SelectObject(oldBrush);
		////pDC->Ellipse(100, 100, 100, 100);

		//重新进入没有选中的状态
		pDoc->Select_elliptical = false;
	}
	else {
		
		
		pDC->Ellipse(pDoc->re);				//绘制椭圆图形
	}
}


// CMFCApplication6View 打印


void CMFCApplication6View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CMFCApplication6View 诊断

#ifdef _DEBUG
void CMFCApplication6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6Doc* CMFCApplication6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6Doc)));
	return (CMFCApplication6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6View 消息处理程序

//在客户区用鼠标拖出椭圆，并显示拖出时的渐变效果；
void CMFCApplication6View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication6Doc* pDoc = GetDocument();
	pDoc ->re.left = point.x;
	pDoc->re.top = point.y;
	pDoc -> a = 1;
		

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication6View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication6Doc* pDoc = GetDocument();
	pDoc->re.right = point.x;
	pDoc ->re.bottom = point.y;
	pDoc->a = 0;
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication6View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication6Doc* pDoc = GetDocument();
	if (pDoc->a) 
	{
		pDoc->re.right = point.x;
		pDoc->re.bottom = point.y;
		Invalidate();

		CView::OnMouseMove(nFlags, point);
	}
}


//(2)  通过点击菜单来弹出对话框，然后在对话框中输入确定椭圆的数据，根据此数据在客户区中画椭圆；
void CMFCApplication6View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	CMFCApplication6Doc* pDoc = GetDocument();
	if (t == IDOK)
	{
		
		
		//left、top分别表示矩形左上角顶点的横坐标和纵坐标，right、bottom分别表示矩形右下角顶点的横坐标和纵坐标
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	

	CView::OnLButtonDblClk(nFlags, point);
}

//鼠标中键的事件处理程序
void CMFCApplication6View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication6Doc* pDoc = GetDocument();
	
	pDoc->Select_elliptical= true;

	Invalidate();
	CView::OnMButtonDown(nFlags, point);
}


void CMFCApplication6View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg1 dlg;
	CMFCApplication6Doc* pDoc = GetDocument();
	int t = dlg.DoModal();
	if (t == IDOK){
		
		pDoc->Rvalue = dlg.RedValue;
		pDoc->Gvalue = dlg.GreenValue;
		pDoc->Bvalue = dlg.BlueValue;

	}
}
