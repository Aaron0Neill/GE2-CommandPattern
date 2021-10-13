#include "button.h"

Button::Button(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string t_btnName, float t_xPos, float t_yPos) : 
    m_renderer(t_renderer),
    m_name(t_btnName),
    m_font(t_font),
    m_buttonIncrease(30),
    m_xPos(t_xPos),
    m_yPos(t_yPos),
    m_showCounter(true)
{
    InitButton(t_renderer, t_xPos, t_yPos);
    InitButtonText(t_renderer, t_font, t_btnName, t_xPos, t_yPos);
    InitCounter(t_renderer, t_font,std::to_string(0), t_xPos, t_yPos);
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
    if (m_showCounter)
        SDL_RenderCopy(m_renderer, m_clickCounter, NULL, &m_counterRect);
}

//*********************************************

void Button::activateButton(MacroCommand* t_macro)
{
    t_macro->addCommand(m_command);

    UpdateCounter();
}

//*********************************************

void Button::onHover()
{
    m_imageRect.w += m_buttonIncrease;
    m_imageRect.h += m_buttonIncrease;
    m_imageRect.x -= m_buttonIncrease / 2;
    m_imageRect.y -= m_buttonIncrease / 2;
}

//*********************************************

void Button::loseHover()
{
    m_imageRect.w -= m_buttonIncrease;
    m_imageRect.h -= m_buttonIncrease;
    m_imageRect.x += m_buttonIncrease / 2;
    m_imageRect.y += m_buttonIncrease / 2;
}

//*********************************************

void Button::assignCommand(Command* t_command)
{
    m_command = t_command;
}

//*********************************************

bool Button::contains(float xPos, float yPos)
{
    if (xPos > m_imageRect.x && xPos < m_imageRect.x + m_imageRect.w)
    {
        if (yPos > m_imageRect.y && yPos < m_imageRect.y + m_imageRect.h)
        {
            return true;
        }
    }
    return false;
}

//*********************************************

void Button::InitButton(SDL_Renderer* t_renderer, float t_x, float t_y)
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

    m_imageRect.x = t_x;
    m_imageRect.y = t_y;

    SDL_FreeSurface(tempSurf);
}

//*********************************************

void Button::InitButtonText(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string t_btnName , float t_x, float t_y)
{
    SDL_Surface* tempSurf = TTF_RenderText_Solid(t_font, t_btnName.c_str(), SDL_Color{255,255,255});

    m_text = SDL_CreateTextureFromSurface(m_renderer, tempSurf);

    SDL_QueryTexture(m_text, NULL, NULL, &m_textRect.w, &m_textRect.h);

    m_textRect.x = t_x + (m_imageRect.w / 2.0f) - (m_textRect.w / 2.0f);
    m_textRect.y = t_y + (m_imageRect.h / 2.0f) - (m_textRect.h / 2.0f);

    if (m_image == nullptr)
        printf(SDL_GetError()); 

    SDL_FreeSurface(tempSurf);
}

//*********************************************

void Button::InitCounter(SDL_Renderer* t_renderer, TTF_Font* t_font,std::string counter, float t_x, float t_y)
{
    SDL_Surface* tempSurf = TTF_RenderText_Solid(t_font, counter.c_str(), SDL_Color{255,255,255});

    m_clickCounter = SDL_CreateTextureFromSurface(m_renderer, tempSurf);

    SDL_QueryTexture(m_clickCounter, NULL, NULL, & m_counterRect.w, & m_counterRect.h);

    m_counterRect.x = t_x + 128 - (m_counterRect.w / 2.0f);
    m_counterRect.y = t_y + 128 + (m_counterRect.h / 2.0f);

    if (m_image == nullptr)
        printf(SDL_GetError()); 

    SDL_FreeSurface(tempSurf);
}

//*********************************************

void Button::UpdateCounter()
{
    if (m_command != nullptr && m_showCounter)
        InitCounter(m_renderer, m_font,std::to_string(m_command->getCount()), m_xPos, m_yPos);
}