#include "Core.hpp"

Core::Core()
    : _window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Pandemic simulator", sf::Style::Fullscreen), _event(), _clock(), _sim(new Simulation(true)), _delta(0), _botline(sf::Vector2f(WINDOW_X, 5)), _rightline(sf::Vector2f(5, WINDOW_Y - 380)), _reset_txt(), _reset(), _play_txt(), _play()
{
    if (!_reset_txt.loadFromFile("src/reset.png"))
        _reset_txt.loadFromFile("reset.png");
    _reset.setTexture(_reset_txt);
    _reset.setPosition(1730, 890);
    if (!_play_txt.loadFromFile("src/play.png"))
        _play_txt.loadFromFile("play.png");
    _play.setTexture(_play_txt);
    _play.setPosition(1730, 700);
    _botline.setPosition(0, SIM_Y);
    _rightline.setPosition(SIM_X, 0);
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
    if (_event.type == sf::Event::MouseButtonPressed) {
        if (_play.getGlobalBounds().contains(_event.mouseButton.x, _event.mouseButton.y))
            _sim = new Simulation(true);
        else if (_reset.getGlobalBounds().contains(_event.mouseButton.x, _event.mouseButton.y))
            _sim = new Simulation(false);
    }
}

void Core::update()
{
    _sim->update(_delta);
}

void Core::display()
{
    _window.clear(sf::Color(20, 20, 199));
    _sim->display(_window);
    _window.draw(_botline);
    _window.draw(_rightline);
    _window.draw(_reset);
    _window.draw(_play);
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