#pragma once
#include "Model.h"
#include "TableView.h"

class Controller {
public:
    Controller(Model* model, TableView* view);
    void initialize();

private:
    Model* model;
    TableView* view;
};
