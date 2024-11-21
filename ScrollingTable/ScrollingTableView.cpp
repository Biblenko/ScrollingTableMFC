
// ScrollingTableView.cpp: реализация класса CScrollingTableView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "ScrollingTable.h"
#endif

#include "ScrollingTableDoc.h"
#include "ScrollingTableView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CScrollingTableView

IMPLEMENT_DYNCREATE(CScrollingTableView, CScrollView)

BEGIN_MESSAGE_MAP(CScrollingTableView, CScrollView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_ONCHANGEFONT, &CScrollingTableView::OnOnchangeFont)
END_MESSAGE_MAP()

// Создание или уничтожение CScrollingTableView

CScrollingTableView::CScrollingTableView() noexcept
{


}

CScrollingTableView::~CScrollingTableView()
{
}

BOOL CScrollingTableView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CScrollingTableView

void CScrollingTableView::OnDraw(CDC* pDC)
{
	CScrollingTableDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect clientRect;
	GetClientRect(&clientRect);

	if (m_Font.m_hObject) {
		CFont* pOldFont = pDC->SelectObject(&m_Font);

		pDC->TextOut(10, 10, _T("Пример текста с текущим шрифтом"));

		pDC->SelectObject(pOldFont); // Восстанавливаем предыдущий шрифт
	}
	else {
		pDC->TextOut(10, 10, _T("Пример текста со стандартным шрифтом"));
	}

	//pDoc->tableView.drawTable(pDC, clientRect);
	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CScrollingTableView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления

	//Editor code
	/*CRect rect;
	GetClientRect(&rect);

	m_RichEdit.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, rect, this, 1001);*/
	//--end

	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Печать CScrollingTableView

BOOL CScrollingTableView::OnPreparePrinting(CPrintInfo* pInfo)
{
	CScrollingTableDoc* pDoc = GetDocument();


	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CScrollingTableView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CScrollingTableView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CScrollingTableView

#ifdef _DEBUG
void CScrollingTableView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CScrollingTableView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CScrollingTableDoc* CScrollingTableView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScrollingTableDoc)));
	return (CScrollingTableDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CScrollingTableView


void CScrollingTableView::OnOnchangeFont()
{
	CFontDialog fontDlg(&m_LogFont);
	if (fontDlg.DoModal() == IDOK) {
		fontDlg.GetCurrentFont(&m_LogFont); // Обновляем параметры шрифта

		// Создаём шрифт и сохраняем его
		if (m_Font.m_hObject) {
			m_Font.DeleteObject(); // Удаляем предыдущий шрифт, если был
		}
		m_Font.CreateFontIndirect(&m_LogFont);

		Invalidate();
	}
}
