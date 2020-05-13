#pragma once


// MyDlg1 对话框

class MyDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg1)

public:
	MyDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 红色的值
	int RedValue;
	// 绿色的值
	int GreenValue;
	// 蓝色的值
	int BlueValue;
};
