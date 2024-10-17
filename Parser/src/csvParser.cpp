#include "csvParser.h"
#include <iostream>
#include <stdexcept>

void CsvParser::openFile(const std::string &filePath)
{
    std::ifstream csvFile(filePath);

    if (!csvFile)
    {
        std::cout << "Failed to open JSON file.";
        return;
    }
    parse(csvFile);
}

void CsvParser::parse(std::ifstream &csvFile)
{
    try
    {
        csvData = rapidcsv::Document(csvFile, rapidcsv::LabelParams(-1, -1));
    }
    catch (const std::exception &exception)
    {
        std::cout << "Error while parsing CSV file:" << exception.what();
    }
}

void CsvParser::print()
{
    std::cout << "CSV File Contents:\n";
    int rows = csvData.GetRowCount();
    int cols = csvData.GetColumnCount();


    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            std::cout << csvData.GetCell<std::string>(col, row) << '\t';
        }
        std::cout << '\n';
    }

}
