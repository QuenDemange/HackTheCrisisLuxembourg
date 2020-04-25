#include "Core.hpp"

Core::Core()
    : _window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Pandemic simulator", sf::Style::Fullscreen), _event(), _clock(), _sim(), _delta(0), _botline(sf::Vector2f(WINDOW_X, 5)), _rightline(sf::Vector2f(5, WINDOW_Y))
{
    _botline.setPosition(0, SIM_Y);
    _rightline.setPosition(SIM_X, 0);
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
}

void Core::update()
{
    for (std::vector<Person>::iterator i = _persons.begin(); i != _persons.end(); ++i)
        i->move(_delta);
}

void Core::display()
{
    _window.clear(sf::Color(20, 20, 199));
    for (std::vector<Person>::iterator i = _persons.begin(); i != _persons.end(); ++i)
        _window.draw(*i->getCircle());
    _window.draw(_botline);
    _window.draw(_rightline);
    _window.display();
}

int Core::launch()
{
    while (_window.isOpen())
    {
        _delta = _clock.restart().asSeconds();
        while (_window.pollEvent(_event))
            processEvents();
        update();
        display();
    }
    return (0);
}