// MyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "MyDlg1.h"
#include "afxdialogex.h"


// MyDlg1 对话框

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, RedValue(0)
	, GreenValue(0)
	, BlueValue(0)
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, RedValue);
	DDV_MinMaxInt(pDX, RedValue, 0, 255);
	DDX_Text(pDX, IDC_EDIT6, GreenValue);
	DDV_MinMaxInt(pDX, GreenValue, 0, 255);
	DDX_Text(pDX, IDC_EDIT7, BlueValue);
	DDV_MinMaxInt(pDX, BlueValue, 0, 255);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
END_MESSAGE_MAP()


// MyDlg1 消息处理程序
