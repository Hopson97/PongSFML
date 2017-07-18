#ifndef CLICKABLE_H_INCLUDED
#define CLICKABLE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <functional>

class ClickableRectangle : public sf::RectangleShape
{
    public:
        ClickableRectangle(std::function<void(void)> onClick,
                           std::function<void(void)> onRollover,
                           std::function<void(void)> onNoTouch,
                           std::function<void(void)> onOffClick = [](){});

        void testForInteration(const sf::RenderWindow& window, sf::Event e);
        void reset();

    private:
        bool isClick(sf::Event e);

        std::function<void(void)> m_onClick;
        std::function<void(void)> m_onRollover;
        std::function<void(void)> m_onNoTouch;
        std::function<void(void)> m_onOffClick;
};

#endif // CLICKABLE_H_INCLUDED
