#ifndef EXPONENTIAL_RANDOM_NUMBER_H
#define EXPONENTIAL_RANDOM_NUMBER_H

#include <random>

class ExponentialRandomNumber
{
private:
    // Mean value for the exponential distribution
    double mean;

    // Create a complete random number generator
    std::random_device random_device;

    // Pseudo random seed for random device
    std::mt19937 random_generator;

    // Creates a uniform real distribution from a range
    std::uniform_real_distribution<double> uniform_random_numbers;

public:
    // Initialize an exponential random number generator
    ExponentialRandomNumber();

    // Set mean for the exponential distribution
    void SetMean(double mean);

    // Returns an exponential random number based on the given mean
    double GetRandomNumber();
};

#endif