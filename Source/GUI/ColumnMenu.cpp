#include "ColumnMenu.h"

namespace GUI
{
    ColumnMenu::ColumnMenu(const sf::RenderWindow& window, float x_pos)
    :   m_basePosition(window.getSize().x / 2, INITIAL_Y_POS)
    {
        m_base.setFillColor(sf::Color(0,0,0,128));
        m_base.setPosition(m_basePosition.x - 300, INITIAL_Y_POS-30);
        m_base.setSize(sf::Vector2f(600, 50));

        //m_offsetPosition = sf::Vector2f(0,0);

        m_xpos = x_pos;
        m_targetxpos = x_pos;
        this->updateXOffsetPosition(x_pos);
        this->update(0.0f);
    }

    void ColumnMenu::handleEvents(sf::Event e, const sf::RenderWindow& win)
    {
        if (abs(m_xpos) < 2)
        {
            for (auto& comp : m_components)
            {
                comp->handleInput(e, win);
            }
        }

    }

    void ColumnMenu::update(float dt)
    {
        //lerp
        if (abs(m_targetxpos - m_xpos) > 0.2) {
            m_xpos = m_xpos + (4*dt) * (m_targetxpos - m_xpos);
            updateXOffsetPosition(m_xpos);
        }

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

    void ColumnMenu::setXOffsetPosition(float x_pos) {
        this->m_targetxpos = x_pos;
    }

    void ColumnMenu::updateXOffsetPosition(float x_pos)
    {
        m_base.setPosition(m_basePosition.x - 300 + x_pos, m_base.getPosition().y);
        for (auto& comp : m_components)
        {
            comp->setPosition(sf::Vector2f(m_basePosition.x - comp->getSize().x / 2 + x_pos,
                                           comp->getPosition().y));
        }
    }


}


