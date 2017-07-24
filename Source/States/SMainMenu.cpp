#include "SMainMenu.h"

#include <iostream>

#include "../Application.h"

#include "../GUI/TextBox.h"

#include "SPlaying.h"

namespace State
{
    StateMenu::StateMenu(Application& application)
    :   StateBase   (application)
    ,   m_frontMenu (application.getWindow())
    {
        initMenus();

        sf::Vector2u w_size = application.getWindow().getSize();
        sf::FloatRect t_size = m_footer.getGlobalBounds();
        m_footer.setPosition(w_size.x-t_size.width-10, w_size.y-t_size.height*2-10);

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
        m_background_shader.setUniform("t", m_shader_time);
        m_frontMenu.update(dt);

        m_gameTitle->update(dt);
    }

    void StateMenu::fixedUpdate(float dt)
    {

    }

    void StateMenu::draw(sf::RenderWindow& window)
    {
        m_background_shader.setUniform("resolution", sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
        window.draw(quad, &m_background_shader);

        m_frontMenu.draw(window);

        window.draw(m_footer);
        m_gameTitle->draw(window);
    }

    void StateMenu::initMenus()
    {
        m_gameTitle = std::make_unique<GameTitle>("ExtremePong", sf::Vector2i(210,30));
        m_frontMenu.addComponent<GUI::TextBox>("Enter IP Here!", m_ipAddress);

        m_frontMenu.addComponent<GUI::Button>("Host",  [&]()
        {
            m_pApplication->pushState<StatePlaying>(*m_pApplication);
        });

        m_frontMenu.addComponent<GUI::Button>("Connect", [&]()
        {
            if (!m_ipAddress.empty())
            {
                m_pApplication->pushState<StatePlaying>(*m_pApplication, m_ipAddress);
            }
        });

        m_footer.setFont(ResourceHolder::getFont("imagine_font"));
        m_footer.setString("A game made by the Hopson Server");
        m_footer.setCharacterSize(24);
    }
}
