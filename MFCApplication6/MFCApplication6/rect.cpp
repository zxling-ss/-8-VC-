// rect.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "rect.h"
#include "afxdialogex.h"


// rect �Ի���

IMPLEMENT_DYNAMIC(rect, CDialogEx)

rect::rect(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

rect::~rect()
{
}

void rect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(rect, CDialogEx)
END_MESSAGE_MAP()


// rect ��Ϣ�������
