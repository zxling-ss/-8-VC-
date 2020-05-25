#pragma once
#include "afxwin.h"


// fileDialog 对话框

class fileDialog : public CDialogEx
{
	DECLARE_DYNAMIC(fileDialog)

public:
	fileDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~fileDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 文件名
	CString m_filename;
	// 列表框文件名
	CString m_listfile;
	virtual BOOL OnInitDialog();
	// 控件类型的变量
	CListBox Listfilename;
};
