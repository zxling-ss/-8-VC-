// fileDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ڰ��ܿ�����ϰ.h"
#include "fileDialog.h"
#include "afxdialogex.h"


// fileDialog �Ի���

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


// fileDialog ��Ϣ�������


BOOL fileDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	Listfilename.AddString(m_filename);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
