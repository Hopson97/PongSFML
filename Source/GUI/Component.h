#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace GUI
{
    class Component
    {
        public:
            Component() = default;
            virtual ~Component() = default;

            virtual sf::Vector2f getSize    () const = 0;

            virtual void setPosition        (const sf::Vector2f& pos) = 0;
            virtual void draw               (sf::RenderWindow& window) = 0;
    };
}

#endif // COMPONENT_H_INCLUDED
