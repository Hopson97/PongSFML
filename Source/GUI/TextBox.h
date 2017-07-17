#ifndef TEXTBOX_H_INCLUDED
#define TEXTBOX_H_INCLUDED

#include <functional>

#include "Component.h"
#include "Clickable.h"

namespace GUI
{
    class TextBox : public Component
    {
        public:
            TextBox(std::string& stringRef);

            sf::Vector2f getSize    () const override;
            void setPosition        (const sf::Vector2f& pos)   override;

            void handleInput        (sf::Event e, const sf::RenderWindow& win) override;
            void draw               (sf::RenderWindow& window)  override;


        private:
            ClickableRectangle m_sprite;
            sf::Text m_text;

            std::string* m_pString = nullptr;
            bool m_isActive = false;
    };
}

#endif // TEXTBOX_H_INCLUDED
