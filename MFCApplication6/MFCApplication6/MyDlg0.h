#pragma once
#include "afxwin.h"


// MyDlg0 �Ի���

class MyDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg0)

public:
	MyDlg0(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg0();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	// ����x����
	CEdit m_edit1;
	// ����y����
	CEdit m_edit2;
	// ����x����
	CEdit m_edit3;
	// ����y����
	CEdit m_edit4;
	// ����x����
	int TopRx;
	// ����y����
	int TopRy;
	// ����x����
	int LowerLx;
	// ����y����// ����y����
	int LowerLy;
};
