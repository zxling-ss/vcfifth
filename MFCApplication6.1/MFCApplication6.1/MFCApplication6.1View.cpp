
// MFCApplication6.1View.cpp: CMFCApplication61View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication6.1.h"
#endif

#include "MFCApplication6.1Doc.h"
#include "MFCApplication6.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication61View

IMPLEMENT_DYNCREATE(CMFCApplication61View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication61View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication61View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCApplication61View 构造/析构

CMFCApplication61View::CMFCApplication61View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication61View::~CMFCApplication61View()
{
}

BOOL CMFCApplication61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication61View 绘图

void CMFCApplication61View::OnDraw(CDC* pDC)
{
	CMFCApplication61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect A1;
	this->GetClientRect(&A1);
//	pDoc->A.right = A1.right;
	pDC->Rectangle(pDoc->A);
	pDC->TextOutW(0, 20, pDoc->s2);
}


// CMFCApplication61View 打印


void CMFCApplication61View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication61View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication61View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication61View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication61View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication61View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication61View 诊断

#ifdef _DEBUG
void CMFCApplication61View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication61Doc* CMFCApplication61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication61Doc)));
	return (CMFCApplication61Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication61View 消息处理程序


void CMFCApplication61View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CMFCApplication61Doc* pDoc = GetDocument();
	pDoc->s1.Format(_T("%c"),nChar);
	if (pDoc->s2.GetLength() <= pDoc->A.right / 10)
	{
		pDoc->s2 = pDoc->s2 + pDoc->s1;
	}
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
