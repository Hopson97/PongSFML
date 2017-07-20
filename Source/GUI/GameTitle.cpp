#include "gametitle.h"

// GAME TITLE OBJECT //

GameTitle::GameTitle(const std::string& title, sf::Vector2i position)
{
    for (unsigned i = 0; i < title.length(); i++)
    {
        int x = position.x + (i*(LETTER_FONT+LETTER_OFFSET));
        int y = position.y;

        // "I" doesn't want to cooperate, smh
        if (title[i] == 'i')
            x += LETTER_FONT/4;

        TitleLetter t_letter = TitleLetter(title[i], x, y, i);
        m_letters.push_back(std::move(t_letter));
    }
}

void GameTitle::update(float dt)
{
    for (auto& t_letter : m_letters)
        t_letter.update(dt);
}

void GameTitle::draw(sf::RenderWindow& window)
{
    for (auto& t_letter : m_letters)
        t_letter.draw(window);
}

sf::Vector2f GameTitle::getSize () const
{
    return {0, 200};
}


// TITLE LETTER OBJECT //

TitleLetter::TitleLetter(char letter, int x_pos, int y_pos, int offset)
{
    m_letter = letter;
    tick += offset * 0.5;

    m_letter_sprite.setFont(ResourceHolder::getFont("imagine_font"));
    m_letter_sprite.setString(m_letter);
    m_letter_sprite.setCharacterSize(LETTER_FONT);
    m_letter_sprite.setPosition(m_position.x, m_position.y);

    m_position = sf::Vector2i(x_pos, y_pos);
}

void TitleLetter::update(float dt)
{
    //old_y = m_letter_sprite.getPosition().y;
    tick += dt;

    old_y = WAVE_HEIGHT/2 + WAVE_HEIGHT*sin((tick-0.2)*WAVE_SPEED);
    new_y = WAVE_HEIGHT/2 + WAVE_HEIGHT*sin(tick*WAVE_SPEED);


    //m_letter_sprite.setPosition(m_position.x,
    //                            m_position.y - WAVE_HEIGHT/2 + WAVE_HEIGHT*sin(tick*WAVE_SPEED));
}

void TitleLetter::draw(sf::RenderWindow& window)
{
    m_letter_sprite.setColor(sf::Color(255, 255, 255, 255));
    m_letter_sprite.setPosition(m_position.x, m_position.y + new_y);
    window.draw(m_letter_sprite);

    // draw trail
    m_letter_sprite.setColor(sf::Color(255, 255, 255, 128));
    m_letter_sprite.setPosition(m_position.x, m_position.y + old_y);
    window.draw(m_letter_sprite);
}
