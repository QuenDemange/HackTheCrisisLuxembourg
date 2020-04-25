/*
** EPITECH PROJECT, 2020
** HackTheCrisisLuxembourg [WSL: Ubuntu]
** File description:
** Person
*/

#include "Person.hpp"
#include "Define.hpp"

Person::Person()
: _body(), _position(), _direction()
{
    _state = ALIVE;
    _position.x = std::rand() % SIM_X;
    _position.y = std::rand() % SIM_Y;
    _body.setFillColor(sf::Color::White);
    _body.setRadius(5);
    _body.setPosition(_position);
    _body.setPointCount(100);
    changeDest();
    calcUnit();
    _speed = 100.0f;
}

void Person::changeDest()
{
    _dest = {std::rand() % static_cast<int> (SIM_X - _body.getRadius()) + _body.getRadius(), std::rand() % static_cast<int> (SIM_Y - _body.getRadius()) + _body.getRadius()};
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

sf::CircleShape *Person::getCircle()
{
    return (&_body);
}

void Person::death()
{
    _state = DEATH;
    _body.setFillColor(sf::Color::Black);
}

bool Person::isArrived()
{
    if (_position.x >= _dest.x - 2 && _position.x <= _dest.x + 2)
        if (_position.y >= _dest.y - 2 && _position.y <= _dest.y + 2)
            return (true);
    return (false);
}

void Person::calcUnit()
{
    _direction = {_dest.x - _position.x, _dest.y - _position.y};
    float longueur = std::sqrt(std::pow(_direction.x, 2) + std::pow(_direction.y, 2));
    _direction.x /= longueur;
    _direction.y /= longueur;
}

void Person::move(float _delta)
{
    if (_state == DEATH)
        return;
    if (isArrived()) {
        changeDest();
        calcUnit();
    }
    _body.move(_direction * _speed * _delta);
    _position = _body.getPosition();
}