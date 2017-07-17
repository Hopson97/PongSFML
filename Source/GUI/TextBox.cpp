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

        m_sprite.setSize({500, 100});
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

        if (e.type == sf::Event::TextEntered && m_isActive)
        {
            //Get the key that was entered
            unsigned char k = e.text.unicode;

            //Test if it within the "Type-able keys eg aA to zZ and 0 to 9
            if (k >= 32 && k <= 127)
            {
                m_pString->push_back(k);
            }
            else if (k == 8) //Backspace
            {
                if (m_pString->length() <= 0)
                    return;
                m_pString->pop_back();
            }

            //Updates the SFML text
            updateText();

            //Don't want the text to go over the size of the box
            //If it does, then backspace it
            if (exeedsSize())
            {
                m_pString->pop_back();
                updateText();
            }
        }
    }

    void TextBox::draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
        window.draw(m_text);
    }

    void TextBox::updateText()
    {
        m_text.setString(*m_pString);
        auto pos = m_sprite.getPosition();
        m_text.setPosition( pos.x + m_sprite.getGlobalBounds().width  / 2 - m_text.getGlobalBounds().width / 2,
                            pos.y + m_sprite.getGlobalBounds().height / 2 - m_text.getGlobalBounds().height / 2);
    }

    bool TextBox::exeedsSize()
    {
        return m_sprite.getLocalBounds().width <= m_text.getLocalBounds().width;

    }
}
