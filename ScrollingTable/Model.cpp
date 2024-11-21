#include "pch.h"
#include "Model.h"

void Model::addRecord(const Record& record) {
    records.push_back(record);
}

const std::vector<Model::Record>& Model::getRecords() const {
    return records;
}
