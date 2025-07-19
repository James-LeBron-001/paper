// RandomUtils.cpp
// Implementation of RandomUtils utility class
#include "RandomUtils.h"
#include <random>
#include <chrono>

namespace {
    // Anonymous namespace for internal linkage
    std::mt19937 rng;
    bool initialized = false;
}

void RandomUtils::initialize() {
    // Initialize random number generator with a time-based seed
    if (!initialized) {
        rng.seed(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
        initialized = true;
    }
}

int RandomUtils::randInt(int min, int max) {
    // Return a random integer in [min, max]
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

double RandomUtils::randDouble() {
    // Return a random double in [0, 1]
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

int RandomUtils::binomial(int n, double p) {
    // Sample from binomial distribution
    std::binomial_distribution<int> dist(n, p);
    return dist(rng);
}

double RandomUtils::exponential(double lambda) {
    // Sample from exponential distribution
    std::exponential_distribution<double> dist(lambda);
    return dist(rng);
} 