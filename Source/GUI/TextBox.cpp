#include "TextBox.h"

#include "../ResourceManager/ResourceHolder.h"

#include <iostream>

#define NONE [](){}

namespace GUI
{
    TextBox::TextBox(std::string& strRef)
    :   m_sprite    ( [&]()
                    {
                        m_isActive = true;
                        m_sprite.setFillColor({150, 150, 255});
                    },
                    NONE, NONE,
                    [&]()
                    {
                        m_isActive = false;
                        m_sprite.setFillColor({200, 200, 255});
                    })
    ,   m_pString   (&strRef)
    {
        m_text.setFont(ResourceHolder::getFont("rs"));

        m_sprite.setSize({300, 100});
        m_sprite.setFillColor({200, 200, 255});
    }

    sf::Vector2f TextBox::getSize() const
    {
        return m_sprite.getSize();
    }

    void TextBox::setPosition(const sf::Vector2f& pos)
    {
        m_sprite.setPosition(pos);
        m_text.setPosition(pos.x + m_sprite.getGlobalBounds().width  / 2 - m_text.getGlobalBounds().width / 2,
                           pos.y + m_sprite.getGlobalBounds().height / 2 - m_text.getGlobalBounds().height / 2);
    }

    void TextBox::handleInput(sf::Event e, const sf::RenderWindow& win)
    {
        m_sprite.testForInteration(win, e);
    }

    void TextBox::draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
        window.draw(m_text);
    }

}
