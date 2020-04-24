#include "Core.hpp"

Core::Core()
: _window(sf::VideoMode(1920, 1080), "Pandemic simulator", sf::Style::Fullscreen), _event(), _clock(), _sim(), _delta(0)
{
    _window.setFramerateLimit(60);
    int n = std::rand() % 100;
    for (int i = 0; i < n; i++)
        _persons.push_back(Person());
    _persons.at(std::rand() % _persons.size()).infected();
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
    // if (_event.type == sf::Event::MouseButtonPressed)
    //     if (_event.mouseButton.button == sf::Mouse::Left)
    //         std::cout << rand();
    //     else
            
}

int Core::launch()
{
    while (_window.isOpen())
    {
        _delta = _clock.restart().asSeconds();
        while (_window.pollEvent(_event))
            processEvents();
        _window.clear(sf::Color(20, 20, 199));
        for (std::vector<Person>::iterator i = _persons.begin(); i != _persons.end(); ++i) {
            i->move(_delta);
            _window.draw(*i->getCircle());
        }
        _window.display();
    }
    return (0);
}