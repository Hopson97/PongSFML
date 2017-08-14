#ifndef COLUMNMENU_H_INCLUDED
#define COLUMNMENU_H_INCLUDED

#include <vector>
#include <memory>

#include "Component.h"

const int INITIAL_Y_POS = 225;

namespace GUI
{
    class ColumnMenu
    {
        public:
            ColumnMenu(const sf::RenderWindow& window, float x_pos);

            template<typename C, typename... Args>
            void addComponent(Args&&... args)
            {
                m_components.push_back(std::make_unique<C>(std::forward<Args>(args)...));
                auto& comp = *m_components.back();
                comp.setPosition({m_basePosition.x - comp.getSize().x / 2, m_basePosition.y});

                update_base_size(comp.getSize().y+20);
                m_basePosition.y += comp.getSize().y+20;
            }

            void handleEvents   (sf::Event e, const sf::RenderWindow& win);
            void update         (float dt);
            void draw           (sf::RenderWindow& window);

            void setXOffsetPosition(float x_pos);

        private:
            std::vector<std::unique_ptr<Component>> m_components;

            sf::Vector2f m_basePosition;
            //sf::Vector2f m_offsetPosition;

            sf::RectangleShape m_base;
            void update_base_size(float y_size);

            float m_targetxpos = 0;
            float m_xpos = 0;
            void updateXOffsetPosition(float x_pos);
    };
}

#endif // COLUMNMENU_H_INCLUDED
