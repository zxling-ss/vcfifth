
// ������ʵ����View.h : C������ʵ����View ��Ľӿ�
//

#pragma once


class C������ʵ����View : public CView
{
protected: // �������л�����
	C������ʵ����View();
	DECLARE_DYNCREATE(C������ʵ����View)

// ����
public:
	C������ʵ����Doc* GetDocument() const;
	CPoint point1;
	CPoint point2;
// ����
public:
	bool line;
	bool line2;
	bool re;
	bool circle;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C������ʵ����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnName();
	
	afx_msg void OnLine();
	afx_msg void OnRect();
	afx_msg void OnCircle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ������ʵ����View.cpp �еĵ��԰汾
inline C������ʵ����Doc* C������ʵ����View::GetDocument() const
   { return reinterpret_cast<C������ʵ����Doc*>(m_pDocument); }
#endif

