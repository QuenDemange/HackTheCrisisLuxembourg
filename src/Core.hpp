#pragma once

#include <SFML/Graphics.hpp>
#include "Simulation.hpp"
#include <iostream>

class Core {
    public:
        Core();
        ~Core();
        
        int launch();
    protected:
    private:
        void processEvents();

        sf::RenderWindow _window;
        sf::Event _event;
        sf::Clock _clock;
        Simulation *_sim;
        float _delta;
};
