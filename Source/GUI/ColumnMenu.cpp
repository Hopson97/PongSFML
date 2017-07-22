#include "ColumnMenu.h"

namespace GUI
{
    ColumnMenu::ColumnMenu(const sf::RenderWindow& window)
    :   m_basePosition(window.getSize().x / 2, INITIAL_Y_POS)
    {
        m_base.setFillColor(sf::Color(0,0,0,128));
        m_base.setPosition(m_basePosition.x - 300, INITIAL_Y_POS-30);
        m_base.setSize(sf::Vector2f(600, 50));
    }

    void ColumnMenu::handleEvents(sf::Event e, const sf::RenderWindow& win)
    {
        for (auto& comp : m_components)
        {
            comp->handleInput(e, win);
        }
    }

    void ColumnMenu::update(float dt)
    {
        for (auto& comp : m_components)
        {
            comp->update(dt);
        }
    }

    void ColumnMenu::draw(sf::RenderWindow& window)
    {
        window.draw(m_base);
        for (auto& comp : m_components)
        {
            comp->draw(window);
        }
    }

    void ColumnMenu::update_base_size(float y_size)
    {
        m_base.setSize(sf::Vector2f(600, m_base.getSize().y + y_size));
    }
}


