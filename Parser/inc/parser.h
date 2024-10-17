#ifndef PARSER_H
#define PARSER_H

#include <string>

class Parser
{
public:
    virtual void openFile(const std::string& filePath)=0;
    virtual void parse(std::ifstream &fileIn) = 0;
    virtual void print() = 0;
    virtual ~Parser() = default;
};

#endif