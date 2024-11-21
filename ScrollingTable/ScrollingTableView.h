
// ScrollingTableView.h: интерфейс класса CScrollingTableView
//

#pragma once


class CScrollingTableView : public CScrollView
{
protected: // создать только из сериализации
	CScrollingTableView() noexcept;
	DECLARE_DYNCREATE(CScrollingTableView)

// Атрибуты
public:
	CScrollingTableDoc* GetDocument() const;
	CFont m_Font;
	LOGFONT m_LogFont;
// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CScrollingTableView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOnchangeFont();
};

#ifndef _DEBUG  // версия отладки в ScrollingTableView.cpp
inline CScrollingTableDoc* CScrollingTableView::GetDocument() const
   { return reinterpret_cast<CScrollingTableDoc*>(m_pDocument); }
#endif

