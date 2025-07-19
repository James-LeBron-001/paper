// SEIRModel.h
// Main class for SEIR epidemic simulation
#pragma once
#include "Population.h"
#include "Migration.h"
#include "Transition.h"
#include "IOUtils.h"
#include "Config.h"

class SEIRModel {
public:
    SEIRModel();
    ~SEIRModel();
    // Initialize model parameters and population
    void initialize();
    // Run the simulation
    void run();
    // Export simulation results
    void exportResults() const;
private:
    Population populationA;
    Population populationB;
    Migration migration;
    Transition transition;
    Config config;
    // Add other members as needed
}; 