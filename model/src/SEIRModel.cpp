// SEIRModel.cpp
// Implementation of SEIRModel class
#include "SEIRModel.h"
#include "RandomUtils.h"
#include <vector>
#include <string>
#include <iostream>

const int EPOCHS = 30;
const int DAYS = 365;

SEIRModel::SEIRModel() {
    // Constructor: initialize members if needed
}

SEIRModel::~SEIRModel() {
    // Destructor: clean up resources if needed
}

void SEIRModel::initialize() {
    // Initialize model parameters and populations
    config.load();
    populationA.initialize(config.ageDistributionA);
    populationB.initialize(config.ageDistributionB);
    RandomUtils::initialize();
}

void SEIRModel::run() {
    // Main simulation loop
    resultsA.clear();
    resultsB.clear();
    for (int epoch = 0; epoch < EPOCHS; ++epoch) {
        populationA.reset();
        populationB.reset();
        std::vector<double> dailyA(DAYS, 0.0);
        std::vector<double> dailyB(DAYS, 0.0);
        for (int day = 0; day < DAYS; ++day) {
            migration.migrate(populationA, populationB, config.migrationRate);
            transition.step(populationA, config, day);
            transition.step(populationB, config, day);
            // Collect daily statistics (e.g., total infected)
            double sumA = 0.0, sumB = 0.0;
            for (int i = 0; i < 18; ++i) {
                for (int j = 0; j < 70000; ++j) {
                    sumA += populationA.I[i][j];
                    sumB += populationB.I[i][j];
                }
            }
            dailyA[day] = sumA;
            dailyB[day] = sumB;
        }
        resultsA.push_back(dailyA);
        resultsB.push_back(dailyB);
        std::cout << "Epoch " << epoch+1 << "/" << EPOCHS << " completed." << std::endl;
    }
}

void SEIRModel::exportResults() const {
    // Export simulation results to CSV files
    IOUtils::writeCSV("results_A.csv", resultsA);
    IOUtils::writeCSV("results_B.csv", resultsB);
    std::cout << "Results exported to results_A.csv and results_B.csv" << std::endl;
} 