
// 第五周实验题View.cpp : C第五周实验题View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周实验题.h"
#endif

#include "第五周实验题Doc.h"
#include "第五周实验题View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周实验题View

IMPLEMENT_DYNCREATE(C第五周实验题View, CView)

BEGIN_MESSAGE_MAP(C第五周实验题View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_Name, &C第五周实验题View::OnName)
	
	ON_COMMAND(ID_Line, &C第五周实验题View::OnLine)
	ON_COMMAND(ID_Rect, &C第五周实验题View::OnRect)
	ON_COMMAND(ID_Circle, &C第五周实验题View::OnCircle)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C第五周实验题View 构造/析构
//3.　添加三个菜单，名字分别为画线、画矩形和画椭圆，当相应菜单被选中的情况下，
//通过鼠标的按下－>拖   动—>抬起， 完成画相应图形

C第五周实验题View::C第五周实验题View()
{
	// TODO: 在此处添加构造代码
	line = false;
	line2 = false;
	re = false;
	circle = false;
}

C第五周实验题View::~C第五周实验题View()
{
}

BOOL C第五周实验题View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周实验题View 绘制

void C第五周实验题View::OnDraw(CDC* pDC)
{
	C第五周实验题Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


// C第五周实验题View 打印

BOOL C第五周实验题View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第五周实验题View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第五周实验题View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第五周实验题View 诊断

#ifdef _DEBUG
void C第五周实验题View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周实验题View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周实验题Doc* C第五周实验题View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周实验题Doc)));
	return (C第五周实验题Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周实验题View 消息处理程序


void C第五周实验题View::OnName()
{
	// TODO: 在此添加命令处理程序代码
	CString s;
	CClientDC dc(this);
	s = _T("名字：张晓灵");
	dc.TextOutW(200, 300, s);
}



void C第五周实验题View::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	/*C第五周实验题Doc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.MoveTo(point.x,point.y);
	dc.LineTo(point.x, point.y);*/
	line = true;
	re = false;
	circle = false;
}


void C第五周实验题View::OnRect()
{

	// TODO: 在此添加命令处理程序代码

	line = false;
	circle = false;
	re = true;

}


void C第五周实验题View::OnCircle()
{
	// TODO: 在此添加命令处理程序代码
	line = false;
	circle = true;
	re = false;
}


void C第五周实验题View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
		point1.x = point.x;
		point1.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void C第五周实验题View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*if (line) */
	{
		point2.x = point.x;
		point2.y = point.y;
		
	}
	CView::OnMouseMove(nFlags, point);
}


void C第五周实验题View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
		point2.x = point.x;
		point2.y = point.y;

	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
