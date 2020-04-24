#pragma once

#include <SFML/Graphics.hpp>

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
        float _delta;
};
