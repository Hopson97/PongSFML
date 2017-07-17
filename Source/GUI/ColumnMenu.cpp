#include "ColumnMenu.h"

namespace GUI
{
    ColumnMenu::ColumnMenu(const sf::RenderWindow& window)
    :   m_basePosition(window.getSize().x / 2,
                       25)
    {
    }

    void ColumnMenu::handleEvents(sf::Event e)
    {
        for (auto& comp : m_components)
        {

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
