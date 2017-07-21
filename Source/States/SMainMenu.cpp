#include "SMainMenu.h"

#include <iostream>

#include "../Application.h"

#include "../GUI/TextBox.h"

namespace
{
    std::string test;
}

namespace State
{
    StateMenu::StateMenu(Application& application)
    :   StateBase   (application)
    ,   m_frontMenu (application.getWindow())
    {
        m_frontMenu.addComponent<GameTitle>("Online Pong", sf::Vector2i(190,20));
        m_frontMenu.addComponent<GUI::TextBox>("Enter IP Here!", test);

        m_host_button = std::make_unique<GUI::Button>("Host",
                        []() { return; });
        m_host_button->setPosition(sf::Vector2f(application.getWindow().getSize().x/2 - 150, 300));

        // Create background shader
        if (!m_background_shader.loadFromFile("Source/Shaders/Menu_Background.frag", sf::Shader::Fragment))
        {
            std::cout << "Error loading 'Menu_Background.frag' shader" << std::endl;
        }
        quad.setFillColor(sf::Color(255,255,255,255));
        quad.setSize(sf::Vector2f(application.getWindow().getSize().x, application.getWindow().getSize().y));
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
        m_shader_time += dt;
        m_background_shader.setParameter("t", m_shader_time);
        m_frontMenu.update(dt);
    }

    void StateMenu::fixedUpdate(float dt)
    {

    }

    void StateMenu::draw(sf::RenderWindow& window)
    {
        window.draw(quad, &m_background_shader);

        m_frontMenu.draw(window);
        m_host_button->draw(window);

    }
}
