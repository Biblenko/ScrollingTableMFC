
// ScrollingTableDoc.h: интерфейс класса CScrollingTableDoc 
//


#pragma once
#include "Model.h"
#include "TableView.h"
#include "Controller.h"


class CScrollingTableDoc : public CDocument
{
protected: // создать только из сериализации
	CScrollingTableDoc() noexcept;
	DECLARE_DYNCREATE(CScrollingTableDoc)

// Атрибуты
public:
	Model model;
	TableView tableView;
	Controller controller;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CScrollingTableDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
