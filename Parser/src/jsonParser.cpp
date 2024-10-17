#include "jsonParser.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void JsonParser::openFile(const std::string &filePath)
{
    std::ifstream jsonFile(filePath);

    if (!jsonFile)
    {
        std::cout << "Failed to open JSON file.";
        return;
    }
    parse(jsonFile);
}

void JsonParser::parse(std::ifstream &jsonFile)
{
    try
    {
        jsonFile >> jsonData;
    }
    catch (const std::exception &exception)
    {
        std::cout << " Error while parsing jsonFile: " << exception.what();
    }
}

void JsonParser::print()
{
    std::cout << "JSON file Contents:\n\n";
    for (const nlohmann::json &employee : jsonData["employees"])
    {
        std::cout << "Name: " << employee["name"] << "\n";
        std::cout << "Age: " << employee["age"] << "\n";
        std::cout << "Occupation: " << employee["occupation"] << "\n";
        std::cout << "Salary: $" << employee["salary"] << "\n";
        std::cout << '\n'<<'\n';
    }
}
