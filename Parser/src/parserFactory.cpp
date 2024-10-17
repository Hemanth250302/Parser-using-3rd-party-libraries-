#include "parserFactory.h"
#include "jsonParser.h"
#include "csvParser.h"
#include "xmlParser.h"

Parser *ParserFactory::createParser(const std::string &fileType)
{
    if (fileType == "json")
    {
        return new JsonParser();
    }
    else if (fileType == "csv")
    {
        return new CsvParser();
    }
    else if (fileType == "xml")
    {
        return new XmlParser();
    }
    else
    {
        throw std::invalid_argument("unsupported Filetype:" + fileType);
    }
}