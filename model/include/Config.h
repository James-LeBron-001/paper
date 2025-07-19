// Config.h
// Configuration and parameters for SEIR model
#pragma once
#include <vector>

class Config {
public:
    Config();
    ~Config();
    // Load configuration from file or set defaults
    void load();
    // Model parameters
    double migrationRate;
    double betaA;
    double betaB;
    double gammaE2;
    double gammaIa;
    double gammaI;
    double exposedPeriod;
    double psyPeriod;
    std::vector<int> ageDistributionA;
    std::vector<int> ageDistributionB;
    // ... add more as needed
}; 