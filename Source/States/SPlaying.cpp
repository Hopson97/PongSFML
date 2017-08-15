#include "SPlaying.h"

#include "../ResourceManager/ResourceHolder.h"

#include "../Animation.h"

namespace State
{
    Animation animation;

    StatePlaying::StatePlaying(Application& application)
    :   StateBase (application)
    {
        player_name = m_pApplication->getNickname();

        m_noticeText.setFont(ResourceHolder::getFont("imagine_font"));
        std::string noticeText_temp = "Player1: " + player_name;
        m_noticeText.setPosition(400, 10);
        m_noticeText.setString(noticeText_temp);

        m_sprite.setTexture(&ResourceHolder::getTexure("test"));
        m_sprite.setSize({32, 32});

        animation.addFrames({16, 16}, {0, 0}, 4, sf::seconds(0.5));

        // IF HOST
        host_thread = new sf::Thread(&StatePlaying::host_waitForPlayer, this);
        host_thread->launch();
    }

    void StatePlaying::handleInput()
    {

    }

    void StatePlaying::handleEvent(sf::Event e)
    {

    }

    void StatePlaying::update(float dt)
    {

        m_sprite.setTextureRect(animation.getFrame());
    }

    void StatePlaying::fixedUpdate(float dt)
    {

    }

    void StatePlaying::draw(sf::RenderWindow& window)
    {
        window.draw(m_noticeText);
        window.draw(m_sprite);
    }

    void StatePlaying::host_waitForPlayer()
    {
        sf::TcpListener listener;
        listener.listen(6969);
        listener.accept(m_tcp_socket);
        std::cout << "Client connect: " << m_tcp_socket.getRemoteAddress() << std::endl;
    }

    StatePlaying::~StatePlaying()
    {
        host_thread->wait();
        delete host_thread;
    }
}
