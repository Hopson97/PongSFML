#ifndef SMAINMENU_H_INCLUDED
#define SMAINMENU_H_INCLUDED

#include "SBase.h"

#include "../GUI/ColumnMenu.h"

namespace State
{
    class StateMenu : public StateBase
    {
        public:
            StateMenu(Application& application);

            void handleInput    ();
            void handleEvent    (sf::Event e);
            void update         (float dt);
            void fixedUpdate    (float dt);
            void draw           (sf::RenderWindow& window);

        private:
            GUI::ColumnMenu m_frontMenu;
    };
}

#endif // SMAINMENU_H_INCLUDED
