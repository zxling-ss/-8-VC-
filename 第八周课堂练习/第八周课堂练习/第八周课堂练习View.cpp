
// 第八周课堂练习View.cpp : C第八周课堂练习View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第八周课堂练习.h"
#endif

#include "第八周课堂练习Doc.h"
#include "第八周课堂练习View.h"
#include "fileDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第八周课堂练习View

IMPLEMENT_DYNCREATE(C第八周课堂练习View, CView)

BEGIN_MESSAGE_MAP(C第八周课堂练习View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32771, &C第八周课堂练习View::On32771)
END_MESSAGE_MAP()

// C第八周课堂练习View 构造/析构

C第八周课堂练习View::C第八周课堂练习View()
{
	// TODO: 在此处添加构造代码

}

C第八周课堂练习View::~C第八周课堂练习View()
{
}

BOOL C第八周课堂练习View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第八周课堂练习View 绘制

void C第八周课堂练习View::OnDraw(CDC* /*pDC*/)
{
	C第八周课堂练习Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第八周课堂练习View 打印

BOOL C第八周课堂练习View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第八周课堂练习View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第八周课堂练习View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第八周课堂练习View 诊断

#ifdef _DEBUG
void C第八周课堂练习View::AssertValid() const
{
	CView::AssertValid();
}

void C第八周课堂练习View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第八周课堂练习Doc* C第八周课堂练习View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第八周课堂练习Doc)));
	return (C第八周课堂练习Doc*)m_pDocument;
}
#endif //_DEBUG


// C第八周课堂练习View 消息处理程序

// (1)　双击鼠标左键，弹出打开文件对话框，从中选择任一个文件名，在客户区显示该文件名；
void C第八周课堂练习View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CFileDialog file(TRUE, NULL, NULL, NULL, NULL, NULL);

	if (IDOK == file.DoModal()) {
		CString filePath = file.GetPathName();

		dc.TextOutW(100, 100, filePath);
		filename = filePath;
	}

	CView::OnLButtonDblClk(nFlags, point);
}

//  (2) 　然后点击某个菜单，弹出一个对话框，使该文件名在对话框中的一个编辑控件中显示出来。
void C第八周课堂练习View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	fileDialog file;
	file.m_filename = filename;
	/*file.m_listfile = filename;*/
	
	UpdateData(false);

	if (IDOK == file.DoModal()) {
		
		
		
	//	UpdateData(true);
	}
	
	
}
