/*
** EPITECH PROJECT, 2020
** HackTheCrisisLuxembourg [WSL: Ubuntu]
** File description:
** Person
*/

#include "Person.hpp"
#include "Define.hpp"

Person::Person(int id)
: _id(id), _body(), _position(), _direction()
{
    _state = ALIVE;
    _position.x = std::rand() % static_cast<int> (SIM_X - _body.getRadius()) + _body.getRadius();
    _position.y = std::rand() % static_cast<int> (SIM_Y - _body.getRadius()) + _body.getRadius();
    _body.setFillColor(sf::Color::White);
    _body.setRadius(10);
    _body.setPosition(_position);
    _body.setPointCount(100);
    changeDest();
    calcUnit();
    _speed = 100.0f;
    _isConfined = false;
    _delta = 0.0f;
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

bool Person::touch(sf::Vector2f position)
{
    if (position.x + _body.getRadius() >= _position.x - _body.getRadius() && position.x - _body.getRadius() <= _position.x + _body.getRadius())
        if (position.y + _body.getRadius() >= _position.y - _body.getRadius() && position.y - _body.getRadius() <= _position.y + _body.getRadius())
            return (true);
    return (false);
}

bool Person::containId(int id)
{
    for (std::list<int>::iterator i = _alreadyCalculate.begin(); i != _alreadyCalculate.end(); ++i)
        if (*i == id)
            return (true);
    return (false);
}

void Person::cleanList(std::vector<Person> persons)
{
    for (std::vector<Person>::iterator i = persons.begin(); i != persons.end(); ++i)
        if (containId(i->_id))
            if (!touch(i->_position))
                _alreadyCalculate.remove(i->_id);
}

void Person::confined()
{
    _isConfined = true;
}

void Person::immune()
{
    _state = IMMUNE;
    _body.setFillColor(sf::Color::Blue);
}

void Person::simulate(std::vector<Person> *persons, float delta) // TO DO Mettre en argument toute les probabilité du menu
{
    float contagious = 30.0f;
    float mortality = 20.0f;
    float timeDisease = 5.0f;

    if (_state != INFECTED)
        return;
    _delta += delta;
    if (_delta >= timeDisease) {
        _delta = 0;
        int r = std::rand() % 101 + 1;
        if (r <= mortality)
            death();
        else
            immune();
        return;
    }
    for (std::vector<Person>::iterator i = (*persons).begin(); i != (*persons).end(); ++i) {
        if (i->_id == _id || containId(i->_id) || i->_state == INFECTED ||i->_state == DEATH || i->_state == IMMUNE)
            continue;
        if (touch(i->_position)) {
            if (std::rand() % 101 + 1 <= contagious) {
                i->infected();
                _alreadyCalculate.push_front(i->_id);
            }
        }
    }
    cleanList(*persons);
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
    if (_position.x >= _dest.x - 5 && _position.x <= _dest.x + 5)
        if (_position.y >= _dest.y - 5 && _position.y <= _dest.y + 5)
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
    if (_state == DEATH || _isConfined)
        return;
    if (isArrived()) {
        changeDest();
        calcUnit();
    }
    _body.move(_direction * _speed * _delta);
    _position = _body.getPosition();
}