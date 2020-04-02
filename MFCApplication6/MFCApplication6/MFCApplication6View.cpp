
// MFCApplication6View.cpp: CMFCApplication6View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication6.h"
#endif

#include "MFCApplication6Doc.h"
#include "MFCApplication6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6View

IMPLEMENT_DYNCREATE(CMFCApplication6View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication6View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication6View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCApplication6View 构造/析构

CMFCApplication6View::CMFCApplication6View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication6View::~CMFCApplication6View()
{
}

BOOL CMFCApplication6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6View 绘图

void CMFCApplication6View::OnDraw(CDC* pDC)
{
	CMFCApplication6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication6View 打印


void CMFCApplication6View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication6View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication6View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication6View 诊断

#ifdef _DEBUG
void CMFCApplication6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6Doc* CMFCApplication6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6Doc)));
	return (CMFCApplication6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6View 消息处理程序


void CMFCApplication6View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);  //建立对象
	int r = cfd.DoModal();  //弹出对话框
		CClientDC dc(this);
	if (r == IDOK)   
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(300, 200, filename);
		CImage img;
		img.Load(filename);

		img.Draw(dc.m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
	}
}
