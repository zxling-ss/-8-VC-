#pragma once
#include "afxwin.h"


// fileDialog �Ի���

class fileDialog : public CDialogEx
{
	DECLARE_DYNAMIC(fileDialog)

public:
	fileDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~fileDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// �ļ���
	CString m_filename;
	// �б���ļ���
	CString m_listfile;
	virtual BOOL OnInitDialog();
	// �ؼ����͵ı���
	CListBox Listfilename;
};
