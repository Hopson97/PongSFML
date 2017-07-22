#ifndef COLUMNMENU_H_INCLUDED
#define COLUMNMENU_H_INCLUDED

#include <vector>
#include <memory>

#include "Component.h"

namespace GUI
{
    class ColumnMenu
    {
        public:
            ColumnMenu(const sf::RenderWindow& window);

            template<typename C, typename... Args>
            void addComponent(Args&&... args)
            {
                m_components.push_back(std::make_unique<C>(std::forward<Args>(args)...));
                auto& comp = *m_components.back();
                comp.setPosition({m_basePosition.x - comp.getSize().x / 2, m_basePosition.y});
                m_basePosition.y += comp.getSize().y+20;
            }

            void handleEvents   (sf::Event e, const sf::RenderWindow& win);
            void update         (float dt);
            void draw           (sf::RenderWindow& window);

        private:
            std::vector<std::unique_ptr<Component>> m_components;
            sf::Vector2f m_basePosition;

    };
}

#endif // COLUMNMENU_H_INCLUDED
