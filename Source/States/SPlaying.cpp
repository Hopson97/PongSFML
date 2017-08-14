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
        std::string noticeText_temp = "Hey, " + player_name;
        m_noticeText.setPosition(400, 10);
        m_noticeText.setString(noticeText_temp);

        m_sprite.setTexture(&ResourceHolder::getTexure("test"));
        m_sprite.setSize({32, 32});

        animation.addFrames({16, 16}, {0, 0}, 4, sf::seconds(0.5));
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
}
