#pragma once
#include <vector>
#include <string>

class Model {
public:
    struct Record {
        std::string field1;
        std::string field2;
        std::string field3;
    };

    void addRecord(const Record& record);
    const std::vector<Record>& getRecords() const;

private:
    std::vector<Record> records;
};
