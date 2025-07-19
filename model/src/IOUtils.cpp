// IOUtils.cpp
// Implementation of IOUtils utility class
#include "IOUtils.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void IOUtils::readCSV(const std::string& path, std::vector<std::vector<double>>& matrix) {
    // Read a CSV file into a matrix
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Cannot open file " + path);
    }
    std::string line;
    while (std::getline(file, line)) {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            if (!cell.empty()) {
                row.push_back(std::stod(cell));
            }
        }
        if (!row.empty()) {
            matrix.push_back(row);
        }
    }
    file.close();
}

void IOUtils::writeCSV(const std::string& path, const std::vector<std::vector<double>>& data) {
    // Write a matrix to a CSV file
    std::ofstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Cannot open file " + path);
    }
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) file << ",";
        }
        file << "\n";
    }
    file.close();
} 