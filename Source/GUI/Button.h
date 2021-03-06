#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <functional>

#include "Component.h"
#include "Clickable.h"

namespace GUI
{
    class Button : public Component
    {
        public:
            Button(std::string&& text, std::function<void(void)> func);

            sf::Vector2f getSize    () const override;
            sf::Vector2f getPosition() const override;
            void setPosition        (const sf::Vector2f& pos)   override;

            void handleInput        (sf::Event e, const sf::RenderWindow& win) override;
            void draw               (sf::RenderWindow& window)  override;


        private:
            ClickableRectangle m_sprite;
            sf::Text m_text;
    };
}

#endif // BUTTON_H_INCLUDED
