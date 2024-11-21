
// ScrollingTable.h: основной файл заголовка для приложения ScrollingTable
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CScrollingTableApp:
// Сведения о реализации этого класса: ScrollingTable.cpp
//

class CScrollingTableApp : public CWinApp
{
public:
	CScrollingTableApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CScrollingTableApp theApp;
