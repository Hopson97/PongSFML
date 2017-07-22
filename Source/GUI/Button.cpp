#include "Button.h"

#include "../ResourceManager/ResourceHolder.h"

#include <iostream>

namespace GUI
{
    Button::Button(std::string&& text, std::function<void(void)> func)
    :   m_sprite    (func,
                    [&](){ m_sprite.setFillColor({150, 150, 255}); },
                    [&](){ m_sprite.setFillColor({200, 200, 255}); })
    {
        m_text.setFont(ResourceHolder::getFont("imagine_font"));
        m_text.setString(std::move(text));

        m_sprite.setSize({300, 50});
        m_sprite.setFillColor({200, 200, 255});
    }

    sf::Vector2f Button::getSize() const
    {
        return m_sprite.getSize();
    }

    void Button::setPosition(const sf::Vector2f& pos)
    {
        m_sprite.setPosition(pos);
        m_text.setPosition(pos.x + m_sprite.getGlobalBounds().width  / 2 - m_text.getGlobalBounds().width / 2,
                           pos.y + m_sprite.getGlobalBounds().height / 3.5 - m_text.getGlobalBounds().height / 2);
    }

    void Button::handleInput(sf::Event e, const sf::RenderWindow& win)
    {
        m_sprite.testForInteration(win, e);
    }

    void Button::draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
        window.draw(m_text);
    }

}
