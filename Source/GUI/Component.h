#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

namespace GUI
{
    class Component
    {
        public:
            Component() = default;
            virtual ~Component() = default;

            virtual void setPosition(const sf::Vector2f& pos) = 0;
            virtual void draw       (sf::RenderWindow& window) = 0;


        private:

    };
}

#endif // COMPONENT_H_INCLUDED
