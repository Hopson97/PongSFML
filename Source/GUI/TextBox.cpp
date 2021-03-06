#include "TextBox.h"

#include "../ResourceManager/ResourceHolder.h"

#include <iostream>

#define NONE [](){}

namespace GUI
{
    TextBox::TextBox(std::string&& label, std::string& strRef)
    :   m_sprite    ([&]() {
                        m_isActive = true;
                        m_sprite.setFillColor({120, 120, 120});
                    },
                    NONE, NONE,
                    [&]() {
                        m_isActive = false;
                        m_sprite.setFillColor({150, 150, 150});
                    })
    ,   m_label     (std::move(label))
    ,   m_pString   (&strRef)
    {
        m_text.setFont(ResourceHolder::getFont("imagine_font"));
        update(0);

        m_sprite.setSize({500, 50});
        m_sprite.setFillColor({150, 150, 150});
    }

    sf::Vector2f TextBox::getSize() const
    {
        return m_sprite.getSize();
    }

    sf::Vector2f TextBox::getPosition() const
    {
        return m_sprite.getPosition();
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

            std::cout << static_cast<int>(k) << std::endl;

            //Test if it within the "Type-able keys eg aA to zZ and 0 to 9
            if (k >= 32 && k <= 127)
            {
                m_pString->push_back(k);
            }
            else if (k == 13 || k == 27) // Enter[13] or Escape[27] causes textbox to Lose focus)
            {
                m_sprite.reset();
            }
            else if (k == 8) //Backspace
            {
                //prevents popping back an empty string
                if (m_pString->length() > 0)
                    m_pString->pop_back();
            }

            //Updates the SFML text
            //updateText();

            //Don't want the text to go over the size of the box
            //If it does, then backspace it
            if (exceedsSize())
            {
                m_pString->pop_back();
                //updateText();
            }
        }
    }

    const std::string& TextBox::getString ()
    {
        if( m_pString->empty())
        {
            m_text.setFillColor({200, 200, 200});
            return m_label;
        }
        else
        {
            m_text.setFillColor({255, 255, 255});
            return *m_pString;
        }
    }

    void TextBox::update(float dt)
    {
        //std::cout << getString() << "\n";
        m_text.setString(getString());
        updateText();
    }

    void TextBox::draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
        window.draw(m_text);
    }

    void TextBox::updateText()
    {
        auto pos = m_sprite.getPosition();
        m_text.setPosition( pos.x + m_sprite.getGlobalBounds().width  / 2 - m_text.getGlobalBounds().width / 2,
                            pos.y + m_sprite.getGlobalBounds().height / 2 - m_text.getGlobalBounds().height);
    }

    bool TextBox::exceedsSize()
    {
        return m_sprite.getLocalBounds().width <= m_text.getLocalBounds().width;

    }
}
