#include "Button.h"

#include "../ResourceManager/ResourceHolder.h"

#include <iostream>

namespace GUI
{
    Button::Button(std::string&& text, std::function<void(void)> func)
    :   m_func  (func)
    {
        m_text.setFont(ResourceHolder::getFont("rs"));
        m_text.setString(std::move(text));

        m_sprite.setSize({300, 100});
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
                           pos.y + m_sprite.getGlobalBounds().height / 2 - m_text.getGlobalBounds().height / 2);
    }

    void Button::handleInput(sf::Event e, const sf::RenderWindow& win)
    {
        if (m_sprite.getGlobalBounds().contains(sf::Mouse::getPosition(win).x,
                                               sf::Mouse::getPosition(win).y))
        {
            std::cout << "test";
            if (e.type == sf::Event::MouseButtonPressed)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    m_func();
                }
            }
            m_sprite.setFillColor({150, 150, 255});
        }
        else
        {
            m_sprite.setFillColor({200, 200, 255});
        }
    }

    void Button::draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
        window.draw(m_text);
    }

}
