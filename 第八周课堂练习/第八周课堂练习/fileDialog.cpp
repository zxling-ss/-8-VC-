// fileDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "第八周课堂练习.h"
#include "fileDialog.h"
#include "afxdialogex.h"


// fileDialog 对话框

IMPLEMENT_DYNAMIC(fileDialog, CDialogEx)

fileDialog::fileDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_filename(_T(""))
	, m_listfile(_T(""))
{

}

fileDialog::~fileDialog()
{
}

void fileDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_filename);
	DDX_LBString(pDX, IDC_LIST1, m_listfile);
	DDX_Control(pDX, IDC_LIST1, Listfilename);
}


BEGIN_MESSAGE_MAP(fileDialog, CDialogEx)
END_MESSAGE_MAP()


// fileDialog 消息处理程序


BOOL fileDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Listfilename.AddString(m_filename);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
