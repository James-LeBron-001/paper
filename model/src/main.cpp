// main.cpp
// Entry point for SEIR epidemic simulation
#include "SEIRModel.h"
#include <iostream>

int main() {
    // Create and initialize the SEIR model
    SEIRModel model;
    model.initialize();
    // Run the simulation
    model.run();
    // Export results to CSV files
    model.exportResults();
    std::cout << "Simulation completed successfully." << std::endl;
    return 0;
} 