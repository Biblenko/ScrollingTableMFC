#include "pch.h"
#include "TableView.h"

TableView::TableView() : model(nullptr) {}

TableView::~TableView() {}

void TableView::setModel(const Model* m) {
    model = m;
}

void TableView::drawTable(CDC* pDC, const CRect& clientRect) {

    int rowHeight = 30;
    int colWidth = clientRect.Width() / 3;


    // Рисуем заголовок
    pDC->Rectangle(clientRect.left, clientRect.top, clientRect.right, clientRect.top + rowHeight);
    pDC->DrawText(L"Field1", CRect(clientRect.left, clientRect.top, clientRect.left + colWidth, clientRect.top + rowHeight), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    pDC->DrawText(L"Field2", CRect(clientRect.left + colWidth, clientRect.top, clientRect.left + 2 * colWidth, clientRect.top + rowHeight), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    pDC->DrawText(L"Field3", CRect(clientRect.left + 2 * colWidth, clientRect.top, clientRect.right, clientRect.top + rowHeight), DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    // Рисуем строки
    int y = clientRect.top + rowHeight;
    for (const auto& record : model->getRecords()) {
        pDC->Rectangle(clientRect.left, y, clientRect.right, y + rowHeight);
        pDC->DrawText((CString)record.field1.c_str(), CRect(clientRect.left, y, clientRect.left + colWidth, y + rowHeight), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        pDC->DrawText((CString)record.field2.c_str(), CRect(clientRect.left + colWidth, y, clientRect.left + 2 * colWidth, y + rowHeight), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        pDC->DrawText((CString)record.field3.c_str(), CRect(clientRect.left + 2 * colWidth, y, clientRect.right, y + rowHeight), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        y += rowHeight;
    }
}
