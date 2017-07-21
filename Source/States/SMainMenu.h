#ifndef SMAINMENU_H_INCLUDED
#define SMAINMENU_H_INCLUDED

#include "SBase.h"

#include "../GUI/ColumnMenu.h"
#include "../GUI/GameTitle.h"
#include "../GUI/Button.h"

#include <memory>

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

            sf::Shader m_background_shader;
            sf::RectangleShape quad;
            float m_shader_time = 0.0f;

            std::unique_ptr<GUI::Button> m_host_button;
            std::unique_ptr<GUI::Button> m_connect_button;
    };
}

#endif // SMAINMENU_H_INCLUDED
