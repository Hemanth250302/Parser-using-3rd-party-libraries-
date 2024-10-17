#include "xmlParser.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void XmlParser::openFile(const std::string &filePath)
{
    std::ifstream xmlFile(filePath);

    if (!xmlFile)
    {
        std::cout << "Failed to open JSON file.";
        return;
    }
    parse(xmlFile);
}

void XmlParser::parse(std::ifstream &jsonFile)
{
    pugi::xml_parse_result result = xmlData.load(jsonFile);
    if (!result)
    {
        throw std::runtime_error("error while parsing XML file: " + std::string(result.description()));
    }
}

void XmlParser::print()
{
    std::cout << "XML Contents: " << std::endl;

    pugi::xml_node employeesNode = xmlData.child("employees");
    for (pugi::xml_node employee = employeesNode.child("employee"); employee; employee = employee.next_sibling("employee"))
    {
        std::cout << "Name: " << employee.child("name").text().as_string() << '\n';
        std::cout << "Age: " << employee.child("age").text().as_int() << '\n';
        std::cout << "Occupation: " << employee.child("occupation").text().as_string() << '\n';
        std::cout << "Salary: " << employee.child("salary").text().as_int() << '\n';
        std::cout << '\n' << '\n';
    }
}
