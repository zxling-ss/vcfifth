
// ������ʵ����View.cpp : C������ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ����.h"
#endif

#include "������ʵ����Doc.h"
#include "������ʵ����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ����View

IMPLEMENT_DYNCREATE(C������ʵ����View, CView)

BEGIN_MESSAGE_MAP(C������ʵ����View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_Name, &C������ʵ����View::OnName)
	
	ON_COMMAND(ID_Line, &C������ʵ����View::OnLine)
	ON_COMMAND(ID_Rect, &C������ʵ����View::OnRect)
	ON_COMMAND(ID_Circle, &C������ʵ����View::OnCircle)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C������ʵ����View ����/����
//3.����������˵������ֱַ�Ϊ���ߡ������κͻ���Բ������Ӧ�˵���ѡ�е�����£�
//ͨ�����İ��£�>��   ����>̧�� ��ɻ���Ӧͼ��

C������ʵ����View::C������ʵ����View()
{
	// TODO: �ڴ˴���ӹ������
	line = false;
	line2 = false;
	re = false;
	circle = false;
}

C������ʵ����View::~C������ʵ����View()
{
}

BOOL C������ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ����View ����

void C������ʵ����View::OnDraw(CDC* pDC)
{
	C������ʵ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (line) {
		pDC->MoveTo(point1.x, point1.y);
		pDC->LineTo(point2.x, point2.y);
		/*if (line2) {
			line = false;
			line2 = false;
		}*/
	}
	if (re) {
		pDC->Rectangle(point1.x, point1.y, point2.x, point2.y);
	}
	if (circle) {
		pDC->Ellipse(point1.x, point1.y, point2.x, point2.y);
	}

}


// C������ʵ����View ��ӡ

BOOL C������ʵ����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ����View ���

#ifdef _DEBUG
void C������ʵ����View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ����Doc* C������ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ����Doc)));
	return (C������ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ����View ��Ϣ�������


void C������ʵ����View::OnName()
{
	// TODO: �ڴ���������������
	CString s;
	CClientDC dc(this);
	s = _T("���֣�������");
	dc.TextOutW(200, 300, s);
}



void C������ʵ����View::OnLine()
{
	// TODO: �ڴ���������������
	/*C������ʵ����Doc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.MoveTo(point.x,point.y);
	dc.LineTo(point.x, point.y);*/
	line = true;
	re = false;
	circle = false;
}


void C������ʵ����View::OnRect()
{

	// TODO: �ڴ���������������

	line = false;
	circle = false;
	re = true;

}


void C������ʵ����View::OnCircle()
{
	// TODO: �ڴ���������������
	line = false;
	circle = true;
	re = false;
}


void C������ʵ����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
		point1.x = point.x;
		point1.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void C������ʵ����View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*if (line) */
	{
		point2.x = point.x;
		point2.y = point.y;
		
	}
	CView::OnMouseMove(nFlags, point);
}


void C������ʵ����View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		point2.x = point.x;
		point2.y = point.y;

	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
