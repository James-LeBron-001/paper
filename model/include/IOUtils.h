// IOUtils.h
// File input/output utilities for SEIR model
#pragma once
#include <string>
#include <vector>

class IOUtils {
public:
    // Read a CSV file into a matrix
    static void readCSV(const std::string& path, std::vector<std::vector<double>>& matrix);
    // Write simulation results to CSV
    static void writeCSV(const std::string& path, const std::vector<std::vector<double>>& data);
}; 