// Transition.cpp
// Implementation of Transition class
#include "Transition.h"
#include "RandomUtils.h"
#include <cmath>

const int AGE_GROUPS = 18;
const int MAX_INDIVIDUALS = 70000;

Transition::Transition() {
    // Constructor
}

Transition::~Transition() {
    // Destructor
}

void Transition::step(Population& population, const Config& config, int day) {
    // Perform SEIR state transitions for each age group
    for (int i = 0; i < AGE_GROUPS; ++i) {
        // Example: S -> E1 (new infections)
        double beta = config.betaA; // or config.betaB, depending on region
        double gammaE2 = config.gammaE2;
        double gammaIa = config.gammaIa;
        double gammaI = config.gammaI;
        double exposedPeriod = config.exposedPeriod;
        double psyPeriod = config.psyPeriod;
        double age_susceptibility = 1.0;
        if (i <= 2) age_susceptibility = 0.58;
        else if (i > 2 && i <= 12) age_susceptibility = 1.0;
        else age_susceptibility = 1.65;
        // Calculate force of infection (simplified, can be extended)
        double infectious = 0.0;
        for (int j = 0; j < AGE_GROUPS; ++j) {
            infectious += gammaE2 * population.E2[j][MAX_INDIVIDUALS-1] + gammaIa * population.Ia[j][MAX_INDIVIDUALS-1] + population.I[j][MAX_INDIVIDUALS-1];
        }
        int S_count = static_cast<int>(population.S[i][0]);
        int new_exposed = RandomUtils::binomial(S_count, beta * infectious * age_susceptibility);
        // S -> E1
        population.S[i][0] -= new_exposed;
        for (int n = 0; n < new_exposed; ++n) {
            int idx = RandomUtils::randInt(0, MAX_INDIVIDUALS-2);
            if (population.E1[i][idx] == 0.0) {
                population.E1[i][idx] = exposedPeriod + 1.0;
                population.flag[i][idx] = 1; // Example: symptomatic
            }
        }
        // E1 -> E2 or Ia
        for (int j = 0; j < MAX_INDIVIDUALS-1; ++j) {
            if (population.E1[i][j] > 0.0) {
                population.E1[i][j] -= 1.0;
                if (population.E1[i][j] == 0.0) {
                    if (population.flag[i][j] == 1) {
                        // E1 -> E2
                        int idx = RandomUtils::randInt(0, MAX_INDIVIDUALS-2);
                        if (population.E2[i][idx] == 0.0) {
                            population.E2[i][idx] = psyPeriod + 1.0;
                        }
                    } else {
                        // E1 -> Ia
                        int idx = RandomUtils::randInt(0, MAX_INDIVIDUALS-2);
                        if (population.Ia[i][idx] == 0.0) {
                            population.Ia[i][idx] = 5.0 + 1.0; // Example duration
                        }
                    }
                    population.flag[i][j] = -1;
                }
            }
        }
        // E2 -> I
        for (int j = 0; j < MAX_INDIVIDUALS-1; ++j) {
            if (population.E2[i][j] > 0.0) {
                population.E2[i][j] -= 1.0;
                if (population.E2[i][j] == 0.0) {
                    int idx = RandomUtils::randInt(0, MAX_INDIVIDUALS-2);
                    if (population.I[i][idx] == 0.0) {
                        population.I[i][idx] = 5.0 + 1.0; // Example duration
                    }
                }
            }
        }
        // Ia -> R
        for (int j = 0; j < MAX_INDIVIDUALS-1; ++j) {
            if (population.Ia[i][j] > 0.0) {
                population.Ia[i][j] -= 1.0;
                if (population.Ia[i][j] == 0.0) {
                    population.R[i] += 1.0;
                }
            }
        }
        // I -> R
        for (int j = 0; j < MAX_INDIVIDUALS-1; ++j) {
            if (population.I[i][j] > 0.0) {
                population.I[i][j] -= 1.0;
                if (population.I[i][j] == 0.0) {
                    population.R[i] += 1.0;
                }
            }
        }
    }
} 