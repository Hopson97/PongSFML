#include "Clickable.h"

#include <iostream>

ClickableRectangle::ClickableRectangle(std::function<void(void)> onClick,
                                       std::function<void(void)> onRollover,
                                       std::function<void(void)> onNoTouch,
                                       std::function<void(void)> onOffClick)
:   m_onClick       (onClick)
,   m_onRollover    (onRollover)
,   m_onNoTouch     (onNoTouch)
,   m_onOffClick    (onOffClick)
{

}

void ClickableRectangle::testForInteration(const sf::RenderWindow& window, sf::Event e)
{
    sf::Vector2f pos((float)sf::Mouse::getPosition(window).x,
                     (float)sf::Mouse::getPosition(window).y);

    if (getGlobalBounds().contains(pos))
    {
        m_onRollover();
        if (isClick(e))
        {
            m_onClick();
        }
    }
    else
    {
        m_onNoTouch();
        if (isClick(e))
        {
            m_onOffClick();
        }
    }


}

bool ClickableRectangle::isClick(sf::Event e)
{
    if (e.type == sf::Event::MouseButtonPressed)
    {
        return (e.mouseButton.button == sf::Mouse::Left);
    }
    else
    {
        return false;
    }
}

void ClickableRectangle::reset() {
    m_onOffClick();
}
