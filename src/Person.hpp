/*
** EPITECH PROJECT, 2020
** HackTheCrisisLuxembourg [WSL: Ubuntu]
** File description:
** Person
*/

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <list>

typedef enum state {
    DEATH,
    ALIVE,
    IMMUNE,
    INFECTED
} state_t;

class Person {
    public:
        Person();
        ~Person();
        void infected();
        void simulate();
        void move(float _delta);
        sf::CircleShape *getCircle();
    private:
        void changeDest();
        bool isArrived();
        void calcUnit();
        void death();
        sf::CircleShape _body;
        state_t _state;
        sf::Vector2f _position;
        sf::Vector2f _direction;
        sf::Vector2f _dest;
        float _speed;
        std::list<int> _alreadyCalculate;
};

#endif /* !PERSON_HPP_ */