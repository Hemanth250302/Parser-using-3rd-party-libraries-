#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "parser.h"
#include "json.h"
#include <string>

class JsonParser : public Parser
{
private:
    nlohmann::json jsonData;

public:
    void openFile(const std::string &filePath) override;
    void parse(std::ifstream &jsonFile) override;
    void print() override;
};
#endif