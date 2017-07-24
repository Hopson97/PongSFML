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
            virtual sf::Vector2f getPosition() const = 0;

            virtual void setPosition        (const sf::Vector2f& pos){}

            virtual void update             (float dt){}
            virtual void handleInput        (sf::Event e, const sf::RenderWindow& win){}
            virtual void draw               (sf::RenderWindow& window) = 0;
    };
}

#endif // COMPONENT_H_INCLUDED
