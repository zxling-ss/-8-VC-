#pragma once
#include "afxwin.h"


// MyDlg0 对话框

class MyDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg0)

public:
	MyDlg0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	// 右上x坐标
	CEdit m_edit1;
	// 右上y坐标
	CEdit m_edit2;
	// 左下x坐标
	CEdit m_edit3;
	// 左下y坐标
	CEdit m_edit4;
	// 右上x坐标
	int TopRx;
	// 右上y坐标
	int TopRy;
	// 左下x坐标
	int LowerLx;
	// 左下y坐标// 左下y坐标
	int LowerLy;
};
