#include "Core.hpp"

Core::Core()
: _window(sf::VideoMode(1920, 1080), "Pandemic simulator"), _event(), _clock(), _delta(0)
{
    _window.setFramerateLimit(60);
}

Core::~Core()
{
}

void Core::processEvents()
{
    if (_event.type == sf::Event::Closed)
        _window.close();
    if (_event.type == sf::Event::KeyPressed)
        if (_event.key.code == sf::Keyboard::Escape)
            _window.close();
}

int Core::launch()
{
    while (_window.isOpen())
    {
        _delta = _clock.restart().asMilliseconds();
        while (_window.pollEvent(_event))
            processEvents();
        _window.clear(sf::Color(20, 20, 199));
        _window.display();
    }
    return (0);
}