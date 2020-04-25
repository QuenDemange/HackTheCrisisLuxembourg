#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Simulation.hpp"

static const int WINDOW_X = 1920;
static const int WINDOW_Y = 1080;

const float R_X = WINDOW_X / 1920;
const float R_Y = WINDOW_Y / 1080;

const int SIM_X = WINDOW_X - 320;
const int SIM_Y = WINDOW_Y - 380;

class Core {
    public:
        Core();
        ~Core();
        
        int launch();
    protected:
    private:
        void processEvents();
        void update();
        void display();

        sf::RenderWindow _window;
        sf::Event _event;
        sf::Clock _clock;
        Simulation *_sim;
        float _delta;
        sf::RectangleShape _botline;
        sf::RectangleShape _rightline;
};
