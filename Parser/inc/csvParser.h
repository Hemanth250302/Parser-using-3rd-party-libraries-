#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "parser.h"
#include "rapidCsv.h"
#include <string>

class CsvParser : public Parser
{
    rapidcsv::Document csvData;

public:
    void openFile(const std::string &filePath) override;
    void parse(std::ifstream &csvFile) override;
    void print() override;
};

#endif