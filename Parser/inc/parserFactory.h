#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#include "parser.h"
#include <string>

class ParserFactory
{
public:
    static Parser *createParser(const std::string &fileType);
};

#endif
