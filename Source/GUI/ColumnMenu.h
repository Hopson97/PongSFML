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
            }

            void handleEvents(sf::Event e);

            void draw(sf::RenderWindow& window);

        private:
            std::vector<std::unique_ptr<Component>> m_components;
            sf::Vector2f m_basePosition;

    };
}

#endif // COLUMNMENU_H_INCLUDED
