#include "ColumnMenu.h"

namespace GUI
{
    ColumnMenu::ColumnMenu(const sf::RenderWindow& window)
    :   m_basePosition(window.getSize().x / 2, 25)
    {
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
        for (auto& comp : m_components)
        {
            comp->draw(window);
        }
    }

}
