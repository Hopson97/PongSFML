#include "Button.h"

#include "../ResourceManager/ResourceHolder.h"

namespace GUI
{
    Button::Button(std::string&& text, std::function<void(void)> func)
    {
        m_text.setFont(ResourceHolder::getFont("rs"));
        m_text.setString(std::move(text));

        m_sprite.setSize({500, 200});
        m_sprite.setFillColor(sf::Color::Blue);
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

    void Button::draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
        window.draw(m_text);
    }

}
