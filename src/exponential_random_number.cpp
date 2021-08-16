#include <random>
#include "exponential_random_number.h"

ExponentialRandomNumber::ExponentialRandomNumber()
{
    // Initialize Mersenne Twister PRNG
    this->random_generator = std::mt19937(this->random_device());

    // Initialize uniform random variable generator
    this->uniform_random_numbers = std::uniform_real_distribution<double>(0, 1);
}

void ExponentialRandomNumber::SetMean(double mean)
{
    this->mean = mean;
}

double ExponentialRandomNumber::GetRandomNumber()
{
    return -log(this->uniform_random_numbers(this->random_generator)) * this->mean;
}
