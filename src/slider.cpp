#include "slider.hpp"

PandemicSlider::PandemicSlider(int x, int y)
{
    xPos = x;
    yPos = y;
    barHeight = 10;
    barWidth = 200;
    sliderHeight = 20;
    sliderWidth = 30;
    if (!font.loadFromFile("../Font/arial.ttf"))
        std::cout << "ERROR with font\n" << std::endl;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    axis.setPosition(x, y);
    axis.setOrigin(0, barHeight / 2);
    axis.setSize(sf::Vector2f(barWidth, barHeight));
    slider.setPosition(x, y);
    slider.setOrigin(sliderWidth / 2, sliderHeight / 2);
    slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
    slider.setFillColor(sf::Color(192, 192, 192));
}

sf::Text PandemicSlider::retText(int x, int y, std::string str, int fontSize)
{
    text.setCharacterSize(fontSize);
    text.setPosition(x, y);
    text.setString(str);
    return text;
}

void PandemicSlider::create(int min, int max)
{
    value = min;
    minValue = min;
    maxValue = max;
}

void PandemicSlider::mouse(sf::RenderWindow &window)
{
    if (slider.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        if (sf::Mouse::getPosition(window).x >= xPos && sf::Mouse::getPosition(window).x <= xPos + barWidth) {
            slider.setPosition(sf::Mouse::getPosition(window).x, yPos);
            value = (minValue + ((slider.getPosition().x - xPos) / barWidth * (maxValue -minValue)));
        }
}

float PandemicSlider::getValue()
{
    return value;
}

void PandemicSlider::setValue(float newValue)
{
    if (newValue >= minValue && newValue <= maxValue) {
        value = newValue;
        float diff = maxValue - minValue;
        float diff2 = newValue - minValue;
        float oui = barWidth / diff;
        float posX = oui * diff2;
        posX += xPos;
        slider.setPosition(posX, yPos);
    }
}

void PandemicSlider::setPercentageValue(float newPercentage)
{
    if (newPercentage >= 0 && newPercentage <= 100) {
        value = newPercentage / 100 * maxValue;
        slider.setPosition(xPos + (barWidth * newPercentage / 100), yPos);
    }
}

void PandemicSlider::draw(sf::RenderWindow &window)
{
    mouse(window);
    window.draw(retText(xPos - 10, yPos + 5, std::to_string(minValue), 20));
    window.draw(axis);
    window.draw(retText(xPos + barWidth - 10, yPos + 5, std::to_string(maxValue), 20));
    window.draw(slider);
    window.draw(retText(slider.getPosition().x - sliderWidth, slider.getPosition().y - sliderHeight, std::to_string((int)value), 15));
}