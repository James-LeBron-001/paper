// Population.cpp
// Implementation of Population class
#include "Population.h"
#include <algorithm>

const int AGE_GROUPS = 18;
const int MAX_INDIVIDUALS = 70000;

Population::Population() {
    // Constructor: initialize state arrays
    S.resize(AGE_GROUPS, std::vector<double>(MAX_INDIVIDUALS, 0.0));
    E1.resize(AGE_GROUPS, std::vector<double>(MAX_INDIVIDUALS, 0.0));
    E2.resize(AGE_GROUPS, std::vector<double>(MAX_INDIVIDUALS, 0.0));
    Ia.resize(AGE_GROUPS, std::vector<double>(MAX_INDIVIDUALS, 0.0));
    I.resize(AGE_GROUPS, std::vector<double>(MAX_INDIVIDUALS, 0.0));
    R.resize(AGE_GROUPS, 0.0);
    flag.resize(AGE_GROUPS, std::vector<int>(MAX_INDIVIDUALS, -1));
}

Population::~Population() {
    // Destructor: nothing to clean up (using std containers)
}

void Population::initialize(const std::vector<int>& ageDist) {
    // Initialize population with given age distribution
    ageDistribution = ageDist;
    reset();
}

void Population::reset() {
    // Reset all state arrays for a new simulation epoch
    for (int i = 0; i < AGE_GROUPS; ++i) {
        std::fill(S[i].begin(), S[i].end(), 0.0);
        std::fill(E1[i].begin(), E1[i].end(), 0.0);
        std::fill(E2[i].begin(), E2[i].end(), 0.0);
        std::fill(Ia[i].begin(), Ia[i].end(), 0.0);
        std::fill(I[i].begin(), I[i].end(), 0.0);
        std::fill(flag[i].begin(), flag[i].end(), -1);
        R[i] = 0.0;
    }
    // Set initial susceptible population according to age distribution
    for (int i = 0; i < AGE_GROUPS; ++i) {
        S[i][0] = static_cast<double>(ageDistribution[i]);
    }
} 