#pragma once


// rect �Ի���

class rect : public CDialogEx
{
	DECLARE_DYNAMIC(rect)

public:
	rect(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~rect();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
