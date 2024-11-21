#pragma once
#include <afxwin.h>
#include "Model.h"

class TableView{
public:
    TableView();
    virtual ~TableView();
    void setModel(const Model* model);
    void drawTable(CDC* pDC, const CRect& clientRect);

private:
    const Model* model;
};
