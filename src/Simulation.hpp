#pragma once

#include <cstdlib>
#include <ctime>

class Simulation {
    public:
        Simulation();
        Simulation(bool changeState);
        ~Simulation();
        void changeSeed();
        void changeSeed(int seed);

    protected:
    private:

        int _seed;
};
