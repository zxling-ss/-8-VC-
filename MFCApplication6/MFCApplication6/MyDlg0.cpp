// MyDlg0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 �Ի���

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


// MyDlg0 ��Ϣ�������


void MyDlg0::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//CString x1;
	//CString y1;
	//CString x2;
	//CString y2;
	// x1 = "";
	// y1 = "";
	// x2 = "";
	// y2 = "";
	// //��ȡ���Ի����е�ֵ
	//m_edit1.GetDlgItemTextW(IDC_EDIT1,x1);
	//m_edit2.GetDlgItemTextW(IDC_EDIT2, y1);
	//m_edit3.GetDlgItemTextW(IDC_EDIT3, x2);
	//m_edit4.GetDlgItemTextW(IDC_EDIT4, y2);

	CClientDC dc(this);		//����һ��CClientDC�Ķ���dc
	//dc.Ellipse(TopRx, TopRy, LowerLx, LowerLy);

	CRect rect;
	this->GetClientRect(rect);
	//left��top�ֱ��ʾ�������ϽǶ���ĺ�����������꣬right��bottom�ֱ��ʾ�������½Ƕ���ĺ������������
	//rect.left = TopRx;
	//rect.top = TopRy;
	//rect.right = LowerLx;
	//rect.bottom = LowerLy;
	dc.Ellipse(rect);
	
	CDialogEx::OnOK();
}


//void MyDlg0::OnEnChangeEdit3()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}
