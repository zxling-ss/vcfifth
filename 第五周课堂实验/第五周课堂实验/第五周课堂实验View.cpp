
// 第五周课堂实验View.cpp : C第五周课堂实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周课堂实验.h"
#endif

#include "第五周课堂实验Doc.h"
#include "第五周课堂实验View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周课堂实验View

IMPLEMENT_DYNCREATE(C第五周课堂实验View, CView)

BEGIN_MESSAGE_MAP(C第五周课堂实验View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_Cicle, &C第五周课堂实验View::OnCicle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C第五周课堂实验View 构造/析构

C第五周课堂实验View::C第五周课堂实验View()
{
	// TODO: 在此处添加构造代码
	ca.SetSize(10);
	ca.Add(rea);
	N = 10;
	rea.top = 0;
	rea.bottom = 0;
	rea.left = 0;
	rea.right = 0;
	//set = true;
	set = false;
	/*C第五周课堂实验Doc* pDoc = GetDocument();
	
		
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

C第五周课堂实验View::~C第五周课堂实验View()
{
}

BOOL C第五周课堂实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周课堂实验View 绘制

void C第五周课堂实验View::OnDraw(CDC* pDC)
{
	C第五周课堂实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	//获取到客户区的中心坐标
	
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
			//设置定时器
			SetTimer(0, 1, NULL);		//第一个参数为第几个定时器，第二个参数为定时器定时的时间，本实验中只有一个圆，因此只需要设置第一个参数为0，即一个定时器
			set = false;				//定时器只需要设置一次，因此，定时器设置之后关闭定时器
		}
	}
	//GetClientRect(pDoc->re);
	//CBrush brush(RGB(50, 250, 250));
	//CBrush* oldBrush=pDC->SelectObject(&brush);  //载入新画刷并把就话说载入指针
	//int a = (pDoc->re.right - pDoc->re.left)/2;
	//int b = (pDoc->re.bottom - pDoc->re.top)/2;
	//pDC->Ellipse(a - 300, b - 300, a + 300, b + 300);
	//pDC->SelectObject(oldBrush);   //在使用新画刷绘制线条之后，恢复原画刷




	
	if (pDoc->a)					//因为需要菜单栏点击之后才开始绘制图像，所以加上限制条件，当点击菜单栏之后打开绘图功能
	{
		//如果颜色值超出范围则进行重置
		if (50 * count > 255)
			count = 1;

		CBrush brush(RGB(50*count, 20*count, 250));
		CBrush* oldBrush = pDC->SelectObject(&brush);  //载入新画刷并把就话说载入指针

		pDC->Ellipse(rea);

		pDC->SelectObject(oldBrush);   //在使用新画刷绘制线条之后，恢复原画刷
	}
	

}


// C第五周课堂实验View 打印

BOOL C第五周课堂实验View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第五周课堂实验View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第五周课堂实验View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第五周课堂实验View 诊断

#ifdef _DEBUG
void C第五周课堂实验View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周课堂实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周课堂实验Doc* C第五周课堂实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周课堂实验Doc)));
	return (C第五周课堂实验Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周课堂实验View 消息处理程序


void C第五周课堂实验View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnLButtonDown(nFlags, point);
}


void C第五周课堂实验View::OnCicle()
{
	// TODO: 在此添加命令处理程序代码
	C第五周课堂实验Doc* pDoc = GetDocument();
	pDoc->a = 1;
	set = true;
	Invalidate();
}


void C第五周课堂实验View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认
	C第五周课堂实验Doc* pDoc = GetDocument();
	/*if (pDoc->a== 1)*/
	{
	int i = nIDEvent;     //第i定时器发生
	CClientDC dc(this);
	CRect re;
	GetClientRect(re);
	pDoc->a = (re.right - re.left) / 2;
	pDoc->b = (re.bottom - re.top) / 2;
	/*dc.Ellipse(pDoc->a - 100, pDoc->b - 100, pDoc->a + 200, pDoc->b + 200);*/
	//思路出了问题，ca中的数据初始值为0，如果只是进行单纯的加减运算，只是在（0，0）坐标上画图，改变的是其半径数据
	//因其，需要重置其，坐标属性即可
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
