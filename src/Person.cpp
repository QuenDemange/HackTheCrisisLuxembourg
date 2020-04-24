/*
** EPITECH PROJECT, 2020
** HackTheCrisisLuxembourg [WSL: Ubuntu]
** File description:
** Person
*/

#include "Person.hpp"

Person::Person()
: _body(), _position(), _direction()
{
    _state = ALIVE;
    _position.x = std::rand() % 1920;
    _position.y = std::rand() % 1080;
    _body.setFillColor(sf::Color::White);
    _body.setRadius(10);
    _speed = 5.0f;
}

Person::~Person()
{
}

void Person::infected()
{
    _state = INFECTED;
    _body.setFillColor(sf::Color::Yellow);
}

void Person::simulate() // TO DO Mettre en argument toute les probabilité du menu
{
    if (_state != INFECTED)
        return;
}

void Person::death()
{
    _state = DEATH;
    _body.setFillColor(sf::Color::Black);
}

void Person::move(float _delta)
{
    if (_state == DEATH)
        return;
    _direction.x = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
    if (std::rand() % 2)
        _direction.x -= 1;
    _direction.y = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
    _body.move(_direction * _speed * _delta);
}