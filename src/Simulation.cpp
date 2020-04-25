#include "Simulation.hpp"

Simulation::Simulation(bool change)
{
    std::cout << "new simulation" << std::endl;

    if (change) {
        std::cout << "changing seed" << std::endl;
        srand(time(NULL));
    }
    else {
        std::cout << "keeping seed" << std::endl;
        srand(1);
    }

    std::cout << rand() << rand() << rand() << std::endl;
    int n = 100;//std::rand() % 100;
    for (int i = 0; i < n; i++)
        _persons.push_back(Person(i));
    _persons.at(std::rand() % _persons.size()).infected();
}

Simulation::~Simulation()
{
}

void Simulation::update(const float _delta)
{
    for (std::vector<Person>::iterator i = _persons.begin(); i != _persons.end(); ++i) {
        i->simulate(&_persons, _delta);
        i->move(_delta);
    }
}

void Simulation::display(sf::RenderWindow &_window)
{
    for (std::vector<Person>::iterator i = _persons.begin(); i != _persons.end(); ++i)
        _window.draw(*i->getCircle());
}