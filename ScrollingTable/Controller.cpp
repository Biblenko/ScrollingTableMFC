#include "pch.h"
#include "Controller.h"

Controller::Controller(Model* m, TableView* v) : model(m), view(v) {}

void Controller::initialize() {
    model->addRecord({ "Product 1", "Category A", "Price 100" });
    model->addRecord({ "Product 2", "Category B", "Price 200" });
    model->addRecord({ "Product 3", "Category C", "Price 300" });

    view->setModel(model);
}
