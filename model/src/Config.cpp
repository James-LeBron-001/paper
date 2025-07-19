// Config.cpp
// Implementation of Config class
#include "Config.h"

Config::Config() {
    // Default model parameters
    migrationRate = 0.0; // Set as needed
    betaA = 0.042943;    // Infection rate for region A (example)
    betaB = 0.0417751;   // Infection rate for region B (example)
    gammaE2 = 1.0;       // Pre-symptomatic infectious rate
    gammaIa = 0.5;       // Asymptomatic infectious rate
    gammaI = 0.2;        // Recovery rate
    exposedPeriod = 3.0; // Average exposed period
    psyPeriod = 2.0;     // Average pre-symptomatic period
    // Age distributions (example values, replace as needed)
    ageDistributionA = {5078,4845,5825,7419,7828,5867,6279,10068,10079,7662,5406,7067,5490,4080,2967,1985,1051,1004};
    ageDistributionB = {5191,4215,4413,7982,9531,7234,6885,8552,9975,9011,6621,6396,4866,3323,2455,1804,830,715};
}

Config::~Config() {
    // Destructor
}

void Config::load() {
    // Load parameters from file or set defaults
} 