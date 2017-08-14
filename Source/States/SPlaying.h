#ifndef SPLAYING_INCLUDED
#define SPLAYING_INCLUDED

#include "../Application.h"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include <iostream>

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
            ~StatePlaying();

            void handleInput    ();
            void handleEvent    (sf::Event e);
            void update         (float dt);
            void fixedUpdate    (float dt);
            void draw           (sf::RenderWindow& window);

        private:
            sf::Mutex m_globalMutex;
            sf::TcpSocket m_tcp_socket;

            std::string player_name;
            std::string opponent_name;

            sf::RectangleShape m_sprite;

            // WAITING FOR PLAYER
            sf::Text m_noticeText;
            sf::Text m_waitingForPlayerText;

            void host_waitForPlayer();
            sf::Thread* host_thread;
    };
}

#endif // SPLAYING_INCLUDED
