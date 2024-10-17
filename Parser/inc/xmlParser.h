#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "parser.h"
#include "pugixml.h"
#include <string>

class XmlParser : public Parser
{
    pugi::xml_document xmlData;

public:
    void openFile(const std::string &filePath) override;
    void parse(std::ifstream &xmlFile) override;
    void print() override;
};

#endif