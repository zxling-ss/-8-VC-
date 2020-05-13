// MyDlg0.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 对话框

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, TopRx(0)
	, TopRy(0)
	, LowerLx(0)
	, LowerLy(0)
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Text(pDX, IDC_EDIT1, TopRx);
	DDX_Text(pDX, IDC_EDIT2, TopRy);
	DDX_Text(pDX, IDC_EDIT3, LowerLx);
	DDX_Text(pDX, IDC_EDIT4, LowerLy);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
	ON_BN_CLICKED(IDOK, &MyDlg0::OnBnClickedOk)
//	ON_EN_CHANGE(IDC_EDIT3, &MyDlg0::OnEnChangeEdit3)
END_MESSAGE_MAP()


// MyDlg0 消息处理程序


void MyDlg0::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//CString x1;
	//CString y1;
	//CString x2;
	//CString y2;
	// x1 = "";
	// y1 = "";
	// x2 = "";
	// y2 = "";
	// //获取到对话框中的值
	//m_edit1.GetDlgItemTextW(IDC_EDIT1,x1);
	//m_edit2.GetDlgItemTextW(IDC_EDIT2, y1);
	//m_edit3.GetDlgItemTextW(IDC_EDIT3, x2);
	//m_edit4.GetDlgItemTextW(IDC_EDIT4, y2);

	CClientDC dc(this);		//定义一个CClientDC的对象dc
	//dc.Ellipse(TopRx, TopRy, LowerLx, LowerLy);

	CRect rect;
	this->GetClientRect(rect);
	//left、top分别表示矩形左上角顶点的横坐标和纵坐标，right、bottom分别表示矩形右下角顶点的横坐标和纵坐标
	//rect.left = TopRx;
	//rect.top = TopRy;
	//rect.right = LowerLx;
	//rect.bottom = LowerLy;
	dc.Ellipse(rect);
	
	CDialogEx::OnOK();
}


//void MyDlg0::OnEnChangeEdit3()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//}
