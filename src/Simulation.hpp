#pragma once

#include <cstdlib>
#include <ctime>
#include "Person.hpp"

class Simulation {
    public:
        Simulation(bool change);
        ~Simulation();
        void changeSeed();
        void changeSeed(int seed);
        void update(const float _delta);
        void display(sf::RenderWindow &_window);

        int getSeed() { return (_seed); }

    protected:
    private:
        int _seed;
        std::vector<Person> _persons;
};
