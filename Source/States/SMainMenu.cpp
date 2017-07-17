#include "SMainMenu.h"

#include <iostream>

#include "../Application.h"

#include "../GUI/Button.h"

namespace State
{
    StateMenu::StateMenu(Application& application)
    :   StateBase   (application)
    ,   m_frontMenu (application.getWindow())
    {
        m_frontMenu.addComponent<GUI::Button>("Testttt", []()
        {
            std::cout << "Pressed\n";
        });
    }

    void StateMenu::handleInput()
    {

    }

    void StateMenu::handleEvent(sf::Event e)
    {
        m_frontMenu.handleEvents(e, m_pApplication->getWindow());
    }

    void StateMenu::update(float dt)
    {

    }

    void StateMenu::fixedUpdate(float dt)
    {

    }

    void StateMenu::draw(sf::RenderWindow& window)
    {
        m_frontMenu.draw(window);
    }
}
