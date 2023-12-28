#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <random>

//Random between x and y
int RandomInt(int x, int y) 
{
    // Create a random number generator
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(x, y); // Define the range

    // Generate and output the random number
    return distr(gen);
}
#endif
