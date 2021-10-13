#include "button.h"

Button::Button(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string t_btnName, float t_xPos, float t_yPos) : 
    m_renderer(t_renderer),
    m_name(t_btnName)
{
    SDL_Surface* tempSurf = IMG_Load("assets/Button.png");

    if (tempSurf == nullptr)
        printf(SDL_GetError());

    m_image =  SDL_CreateTextureFromSurface(m_renderer, tempSurf);

    if (m_image == nullptr)
        printf(SDL_GetError()); 

    SDL_QueryTexture(m_image, NULL, NULL, &m_imageRect.w, &m_imageRect.h);
    m_imageRect.w *= 2;
    m_imageRect.h *= 2;

    m_imageRect.x = t_xPos;
    m_imageRect.y = t_yPos;

    SDL_Surface* t = TTF_RenderText_Solid(t_font, t_btnName.c_str(), SDL_Color{255,255,255});

    m_text = SDL_CreateTextureFromSurface(m_renderer, t);

    SDL_QueryTexture(m_text, NULL, NULL, &m_textRect.w, &m_textRect.h);

    m_textRect.x = t_xPos + (m_imageRect.w / 2.0f) - (m_textRect.w / 2.0f);
    m_textRect.y = t_yPos + (m_imageRect.h / 2.0f) - (m_textRect.h / 2.0f);

    if (m_image == nullptr)
        printf(SDL_GetError()); 

    SDL_FreeSurface(tempSurf);
}

//*********************************************
Button::~Button()
{
    SDL_DestroyTexture(m_image);
    SDL_DestroyTexture(m_text);
}

//*********************************************

void Button::draw()
{
    SDL_RenderCopy(m_renderer, m_image, NULL, &m_imageRect);
    SDL_RenderCopy(m_renderer, m_text, NULL, &m_textRect);
}