
// �����ܿ���ʵ��View.cpp : C�����ܿ���ʵ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܿ���ʵ��.h"
#endif

#include "�����ܿ���ʵ��Doc.h"
#include "�����ܿ���ʵ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ܿ���ʵ��View

IMPLEMENT_DYNCREATE(C�����ܿ���ʵ��View, CView)

BEGIN_MESSAGE_MAP(C�����ܿ���ʵ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_Cicle, &C�����ܿ���ʵ��View::OnCicle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C�����ܿ���ʵ��View ����/����

C�����ܿ���ʵ��View::C�����ܿ���ʵ��View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(10);
	ca.Add(rea);
	N = 10;
	rea.top = 0;
	rea.bottom = 0;
	rea.left = 0;
	rea.right = 0;
	//set = true;
	set = false;
	/*C�����ܿ���ʵ��Doc* pDoc = GetDocument();
	
		
		CClientDC dc(this);
		CRect re;
		GetClientRect(re);
		pDoc->a = (re.right - re.left) / 2;
		pDoc->b = (re.bottom - re.top) / 2;

		rea.top = (pDoc->b - 10);
		rea.left = (pDoc->a - 10);
		rea.right = (pDoc->a + 10);

		rea.bottom = (pDoc->b + 10);*/

}

C�����ܿ���ʵ��View::~C�����ܿ���ʵ��View()
{
}

BOOL C�����ܿ���ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ܿ���ʵ��View ����

void C�����ܿ���ʵ��View::OnDraw(CDC* pDC)
{
	C�����ܿ���ʵ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	//��ȡ���ͻ�������������
	
	/*pDC->Ellipse(rea);*/
	//for (int i = 0; i < N; i++)
	//{
	//	pDC->Ellipse(rea);
	///*	dc.Ellipse(pDoc->a - i*50, pDoc->b - i * 50, pDoc->a + i * 50, pDoc->b + i * 50);*/
	//}
	
	if (set)
	{
		/*for (int i = 0; i < N; i++) */
		{
			//���ö�ʱ��
			SetTimer(0, 1, NULL);		//��һ������Ϊ�ڼ�����ʱ�����ڶ�������Ϊ��ʱ����ʱ��ʱ�䣬��ʵ����ֻ��һ��Բ�����ֻ��Ҫ���õ�һ������Ϊ0����һ����ʱ��
			set = false;				//��ʱ��ֻ��Ҫ����һ�Σ���ˣ���ʱ������֮��رն�ʱ��
		}
	}
	//GetClientRect(pDoc->re);
	//CBrush brush(RGB(50, 250, 250));
	//CBrush* oldBrush=pDC->SelectObject(&brush);  //�����»�ˢ���Ѿͻ�˵����ָ��
	//int a = (pDoc->re.right - pDoc->re.left)/2;
	//int b = (pDoc->re.bottom - pDoc->re.top)/2;
	//pDC->Ellipse(a - 300, b - 300, a + 300, b + 300);
	//pDC->SelectObject(oldBrush);   //��ʹ���»�ˢ��������֮�󣬻ָ�ԭ��ˢ




	
	if (pDoc->a)					//��Ϊ��Ҫ�˵������֮��ſ�ʼ����ͼ�����Լ�������������������˵���֮��򿪻�ͼ����
	{
		//�����ɫֵ������Χ���������
		if (50 * count > 255)
			count = 1;

		CBrush brush(RGB(50*count, 20*count, 250));
		CBrush* oldBrush = pDC->SelectObject(&brush);  //�����»�ˢ���Ѿͻ�˵����ָ��

		pDC->Ellipse(rea);

		pDC->SelectObject(oldBrush);   //��ʹ���»�ˢ��������֮�󣬻ָ�ԭ��ˢ
	}
	

}


// C�����ܿ���ʵ��View ��ӡ

BOOL C�����ܿ���ʵ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�����ܿ���ʵ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�����ܿ���ʵ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�����ܿ���ʵ��View ���

#ifdef _DEBUG
void C�����ܿ���ʵ��View::AssertValid() const
{
	CView::AssertValid();
}

void C�����ܿ���ʵ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ܿ���ʵ��Doc* C�����ܿ���ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ܿ���ʵ��Doc)));
	return (C�����ܿ���ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C�����ܿ���ʵ��View ��Ϣ�������


void C�����ܿ���ʵ��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CView::OnLButtonDown(nFlags, point);
}


void C�����ܿ���ʵ��View::OnCicle()
{
	// TODO: �ڴ���������������
	C�����ܿ���ʵ��Doc* pDoc = GetDocument();
	pDoc->a = 1;
	set = true;
	Invalidate();
}


void C�����ܿ���ʵ��View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��
	C�����ܿ���ʵ��Doc* pDoc = GetDocument();
	/*if (pDoc->a== 1)*/
	{
	int i = nIDEvent;     //��i��ʱ������
	CClientDC dc(this);
	CRect re;
	GetClientRect(re);
	pDoc->a = (re.right - re.left) / 2;
	pDoc->b = (re.bottom - re.top) / 2;
	/*dc.Ellipse(pDoc->a - 100, pDoc->b - 100, pDoc->a + 200, pDoc->b + 200);*/
	//˼·�������⣬ca�е����ݳ�ʼֵΪ0�����ֻ�ǽ��е����ļӼ����㣬ֻ���ڣ�0��0�������ϻ�ͼ���ı������뾶����
	//���䣬��Ҫ�����䣬�������Լ���
	/*ca[i].top -= (pDoc->b+10);
	ca[i].left -= (pDoc->a + 10);
	ca[i].right += (pDoc->a + 10);

	ca[i].bottom += (pDoc->b + 10);*/


	rea.top = (pDoc->b - count*10);
	rea.left = (pDoc->a - count * 10);
	rea.right = (pDoc->a + count * 10);

	rea.bottom = (pDoc->b + count * 10);
	
	count++;		
	Invalidate();
	}

	CView::OnTimer(nIDEvent);
}
