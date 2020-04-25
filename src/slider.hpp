#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class PandemicSlider
{
    int minValue;
    int maxValue;
    int xPos;
    int yPos;
    int barHeight;
    int barWidth;
    int sliderHeight;
    int sliderWidth;
    float value;
    sf::RectangleShape slider;
    sf::RectangleShape axis;
    sf::Font font;
    sf::Text text;

    public:
        PandemicSlider(int x, int y);
        sf::Text retText(int x, int y, std::string str, int fontSize);
        void create(int min, int max);
        float getValue();
        void mouse(sf::RenderWindow &window);
        void setValue(float newValue);
        void setPercentageValue(float newPercentage);
        void draw(sf::RenderWindow &window);
};