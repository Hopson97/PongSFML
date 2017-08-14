#include "SMainMenu.h"

#include <iostream>

#include "../Application.h"

#include "../GUI/TextBox.h"

namespace
{
    std::string test;
    std::string ip;
}

namespace State
{
    StateMenu::StateMenu(Application& application)
    :   StateBase   (application)
    ,   m_frontMenu (application.getWindow(), 0)
    ,   m_ipMenu (application.getWindow(), -1283)
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
        m_ipMenu.handleEvents(e, m_pApplication->getWindow());
    }

    void StateMenu::update(float dt)
    {
        m_shader_time += dt;
        m_background_shader.setUniform("t", m_shader_time);

        m_frontMenu.update(dt);
        m_ipMenu.update(dt);

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
        m_ipMenu.draw(window);

        window.draw(m_footer);
        m_gameTitle->draw(window);
    }

    void StateMenu::initMenus()
    {
        m_gameTitle = std::make_unique<GameTitle>("ExtremePong", sf::Vector2f(210,30));
        m_frontMenu.addComponent<GUI::TextBox>("Enter Your Nickname!", test);

        m_frontMenu.addComponent<GUI::Button>("Host", [&]()
                                              {
                                              m_pApplication->HostGame(test);
                                              return;
                                              });
        m_frontMenu.addComponent<GUI::Button>("Connect", [&]() {
                                              m_ipMenu.setXOffsetPosition(0);
                                              m_frontMenu.setXOffsetPosition(1280);
                                              return;
                                              });

        m_footer.setFont(ResourceHolder::getFont("imagine_font"));
        m_footer.setString("A game made by the Hopson & Bag");
        m_footer.setCharacterSize(24);

        m_ipMenu.addComponent<GUI::TextBox>("Enter IP here!", ip);
        m_ipMenu.addComponent<GUI::Button>("Start Game", [&]() {
                                           this->validateIP(ip);
                                           return;
                                           });
        /*m_ipMenu.addComponent<GUI::Button>("Back", [&]() {
                                           m_ipMenu.setXOffsetPosition(-1280);
                                           m_frontMenu.setXOffsetPosition(0);
                                           return; });*/

        m_ipMenu.setXOffsetPosition(-1280);
    }

    bool StateMenu::validateIP(const std::string& ip)
    {
        // TODO: make this a new thread
        std::cout << "Connecting to " << ip << ":6969" << std::endl;

        // connect
        sf::TcpSocket test_socket;
        sf::Socket::Status test_status = test_socket.connect(ip, 6969);

        std::cout << "Status: " << test_status << std::endl;

        return false;
    }
}
