﻿#pragma once


// MyDlg0 对话框

class MyDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg0)

public:
	MyDlg0(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MyDlg0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	CButton 相加;
	int z;
	afx_msg void OnBnClickedButton1();
	afx_msg void On32771();
};
