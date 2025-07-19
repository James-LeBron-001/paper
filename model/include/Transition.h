// Transition.h
// State transition logic for SEIR model
#pragma once
#include "Population.h"
#include "Config.h"

class Transition {
public:
    Transition();
    ~Transition();
    // Perform state transitions for a population
    void step(Population& population, const Config& config, int day);
}; 