#include "Simulation.hpp"

Simulation::Simulation()
{
    changeSeed();
}

Simulation::~Simulation()
{
}

void Simulation::changeSeed()
{
    srand(time(NULL));
    _seed = rand();
    srand(_seed);
}