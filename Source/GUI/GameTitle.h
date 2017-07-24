#ifndef GAMETITLE_H
#define GAMETITLE_H

#include <cmath>

#include "../ResourceManager/ResourceHolder.h"
#include <SFML/Graphics.hpp>

#include "Component.h"

const int LETTER_FONT   = 96;
const int LETTER_OFFSET = -16;
const int WAVE_HEIGHT   = 12;
const float WAVE_SPEED  = 3;

class TitleLetter
{
    public:
        TitleLetter(char letter, int x_pos, int y_pos, int offset);

        void update(float dt);
        void draw(sf::RenderWindow& window);

    private:
        char m_letter;
        sf::Text m_letter_sprite;

        sf::Vector2i m_position;

        float old_y = 0;
        float new_y = 0;
        float tick = 0;
};

class GameTitle : public GUI::Component
{
    public:
        GameTitle(const std::string& title, sf::Vector2f position);

        sf::Vector2f getSize    () const override;
        sf::Vector2f getPosition() const override;
        void update             (float dt) override;
        void draw               (sf::RenderWindow& window) override;

    private:
        std::vector<TitleLetter> m_letters;

        sf::Vector2f m_position;
};

#endif // GAMETITLE_H
