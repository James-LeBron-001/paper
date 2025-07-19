// Migration.h
// Migration logic for SEIR model
#pragma once
#include "Population.h"

class Migration {
public:
    Migration();
    ~Migration();
    // Perform migration between two populations
    void migrate(Population& popA, Population& popB, double migrationRate);
}; 