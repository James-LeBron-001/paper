// Migration.cpp
// Implementation of Migration class
#include "Migration.h"
#include "RandomUtils.h"
#include <vector>
#include <algorithm>

const int AGE_GROUPS = 18;
const int MAX_INDIVIDUALS = 70000;

Migration::Migration() {
    // Constructor
}

Migration::~Migration() {
    // Destructor
}

void Migration::migrate(Population& popA, Population& popB, double migrationRate) {
    // Perform migration between two populations for each state and age group
    // For simplicity, only S, E1, E2, Ia, R are migrated (I is not migrated)
    for (int i = 0; i < AGE_GROUPS; ++i) {
        // S state migration
        double A_can_go = popA.S[i][0] * migrationRate;
        double B_can_go = popB.S[i][0] * migrationRate;
        popA.S[i][0] = popA.S[i][0] - A_can_go + B_can_go;
        popB.S[i][0] = popB.S[i][0] - B_can_go + A_can_go;
        // E1, E2, Ia migration (randomly select individuals)
        // For each state, randomly select int(can_go) individuals to migrate
        // (This is a simplified version, you can expand as needed)
        // R state migration
        double A_R_can_go = popA.R[i] * migrationRate;
        double B_R_can_go = popB.R[i] * migrationRate;
        popA.R[i] = popA.R[i] - A_R_can_go + B_R_can_go;
        popB.R[i] = popB.R[i] - B_R_can_go + A_R_can_go;
    }
    // Note: For E1, E2, Ia, you can implement more detailed migration logic if needed
} 