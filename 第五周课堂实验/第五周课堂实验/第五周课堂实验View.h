
// �����ܿ���ʵ��View.h : C�����ܿ���ʵ��View ��Ľӿ�
//

#pragma once


class C�����ܿ���ʵ��View : public CView
{
protected: // �������л�����
	C�����ܿ���ʵ��View();
	DECLARE_DYNCREATE(C�����ܿ���ʵ��View)

// ����
public:
	C�����ܿ���ʵ��Doc* GetDocument() const;
	CArray<CRect, CRect&> ca;
	CRect rea;
	int N;
	bool set;
	int count = 1;		//����ȷ����ʱ���������ٴ�
// ����
public:

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
	virtual ~C�����ܿ���ʵ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCicle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // �����ܿ���ʵ��View.cpp �еĵ��԰汾
inline C�����ܿ���ʵ��Doc* C�����ܿ���ʵ��View::GetDocument() const
   { return reinterpret_cast<C�����ܿ���ʵ��Doc*>(m_pDocument); }
#endif

