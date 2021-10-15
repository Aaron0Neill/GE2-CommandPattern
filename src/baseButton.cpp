#include "Buttons/baseButton.h"

Button::Button(SDL_Renderer* t_renderer, TTF_Font* t_ttf, std::string t_btnName, float t_xPos, float t_yPos) : 
    m_sizeIncrease(10),
    m_count(0),
    m_showCount(true)
{
    m_textureRect.x = t_xPos;
    m_textureRect.y = t_yPos;

    initButtonTexture(t_renderer);
    initButtonText(t_renderer, t_ttf, t_btnName);
    updateCounter(t_renderer, t_ttf);

    m_counterRect.x = m_textureRect.x + (m_textureRect.w / 2.0f);
    m_counterRect.y = m_textureRect.y + m_textureRect.h + 10;
}

//▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂

Button::~Button()
{
    SDL_DestroyTexture(m_buttonText);
    SDL_DestroyTexture(m_buttonTexture);
}

//▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂

void Button::onHover()
{
    m_textureRect.w += m_sizeIncrease;
    m_textureRect.h += m_sizeIncrease;
    m_textureRect.x -= m_sizeIncrease / 2;
    m_textureRect.y -= m_sizeIncrease / 2;
}

//▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂

void Button::loseHover()
{
    m_textureRect.w -= m_sizeIncrease;
    m_textureRect.h -= m_sizeIncrease;
    m_textureRect.x += m_sizeIncrease / 2;
    m_textureRect.y += m_sizeIncrease / 2;
}

//▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂

void Button::updateCounter(SDL_Renderer* t_renderer, TTF_Font* t_ttf)
{
    SDL_Surface* tempSurf = TTF_RenderText_Solid(t_ttf, std::to_string(m_count).c_str(), SDL_Color{255,255,255,255});

    if (tempSurf == nullptr)
        printf(SDL_GetError());

    m_buttonCounter = SDL_CreateTextureFromSurface(t_renderer, tempSurf);

    if (m_buttonCounter == nullptr)
        printf(SDL_GetError()); 

    SDL_QueryTexture(m_buttonCounter, NULL, NULL, &m_counterRect.w, &m_counterRect.h);

    SDL_FreeSurface(tempSurf);
}

//▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂

void Button::activateButton()
{
    if (m_command != nullptr)
        m_command->execute();
}

void Button::undoButton()
{
    if (m_command != nullptr)
        m_command->undo();
}

//▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂

void Button::draw(SDL_Renderer* t_renderer)
{
    SDL_RenderCopy(t_renderer, m_buttonTexture, NULL, &m_textureRect);
    SDL_RenderCopy(t_renderer, m_buttonText, NULL, &m_textRect);
    if (m_showCount)
        SDL_RenderCopy(t_renderer, m_buttonCounter, NULL, &m_counterRect);
}

//▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂

bool Button::contains(float t_xPos, float t_yPos)
{
    if (t_xPos > m_textureRect.x && t_xPos < m_textureRect.x + m_textureRect.w)
    {
        if (t_yPos > m_textureRect.y && t_yPos < m_textureRect.y + m_textureRect.h)
        {
            return true;
        }
    }
    return false;
}

//▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂

void Button::initButtonTexture(SDL_Renderer* t_renderer)
{
    SDL_Surface* tempSurf = IMG_Load("assets/Button.png"); // load in the texture

    if (tempSurf == nullptr)
        printf(SDL_GetError());

    m_buttonTexture = SDL_CreateTextureFromSurface(t_renderer, tempSurf);

    if (m_buttonTexture == nullptr)
        printf(SDL_GetError()); 

    SDL_QueryTexture(m_buttonTexture, NULL, NULL, &m_textureRect.w, &m_textureRect.h);
    m_textureRect.w *= 2; // scale it up
    m_textureRect.h *= 2;

    SDL_FreeSurface(tempSurf);
}

//▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂▂▃▅▇█▓▒░░▒▓█▇▅▃▂

void Button::initButtonText(SDL_Renderer* t_renderer, TTF_Font* t_ttf, std::string t_btnName)
{
    SDL_Surface* tempSurf = TTF_RenderText_Solid(t_ttf, t_btnName.c_str(), SDL_Color{255,255,255});

    m_buttonText = SDL_CreateTextureFromSurface(t_renderer, tempSurf);

    SDL_QueryTexture(m_buttonText, NULL, NULL, &m_textRect.w, &m_textRect.h);

    m_textRect.x = m_textureRect.x + (m_textureRect.w / 2.0f) - (m_textRect.w / 2.0f);
    m_textRect.y = m_textureRect.y+ (m_textureRect.h / 2.0f) - (m_textRect.h / 2.0f);

    if (m_buttonText == nullptr)
        printf(SDL_GetError()); 

    SDL_FreeSurface(tempSurf);
}