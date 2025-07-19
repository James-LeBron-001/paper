// RandomUtils.h
// Random number utilities for SEIR model
#pragma once
#include <random>

class RandomUtils {
public:
    // Initialize random number generator
    static void initialize();
    // Get a random integer in [min, max]
    static int randInt(int min, int max);
    // Get a random double in [0, 1]
    static double randDouble();
    // Sample from binomial distribution
    static int binomial(int n, double p);
    // Sample from exponential distribution
    static double exponential(double lambda);
}; 