
// MFCApplication6Doc.h : CMFCApplication6Doc 类的接口
//


#pragma once


class CMFCApplication6Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFCApplication6Doc();
	DECLARE_DYNCREATE(CMFCApplication6Doc)

// 特性
public:
	CRect re;
	int a;		//用于记录鼠标的状态
	bool Select_elliptical;
		
	int Rvalue;			//用于记录红色值
	int Gvalue;			//用于记录绿色值
	int Bvalue;			//用于记录蓝色值
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFCApplication6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
