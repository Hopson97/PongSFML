#ifndef SPLAYING_INCLUDED
#define SPLAYING_INCLUDED

#include "../Application.h"

#include "SBase.h"

enum class gState
{
    WAITING_FOR_PLAYER,
    READY,
    GAMEPLAY,
};

namespace State
{
    class StatePlaying : public StateBase
    {
        public:
            StatePlaying(Application& application);

            void handleInput    ();
            void handleEvent    (sf::Event e);
            void update         (float dt);
            void fixedUpdate    (float dt);
            void draw           (sf::RenderWindow& window);

        private:
            std::string player_name;
            std::string opponent_name;

            sf::RectangleShape m_sprite;

            // WAITING FOR PLAYER
            sf::Text m_noticeText;
            sf::Text m_waitingForPlayerText;
    };
}

#endif // SPLAYING_INCLUDED
