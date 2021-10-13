#ifndef BUTTON_INCLUDE
#define BUTTON_INCLUDE

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <cstdio>
#include "command.h"
#include "macroCommand.h"

class Button
{
public:
    Button(SDL_Renderer* t_renderer, TTF_Font* t_font,  std::string t_btnName, float t_xPos, float t_yPos);
    virtual ~Button();
    virtual void draw();

    virtual void assignCommand(Command* t_command);

    virtual void activateButton(MacroCommand* t_macro);

    virtual void onHover();

    virtual void loseHover();

    virtual bool contains(float xPos, float yPos);

    virtual void UpdateCounter();

protected:

    virtual void InitButton(SDL_Renderer* t_renderer, float x, float y);

    virtual void InitButtonText(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string , float, float);

    virtual void InitCounter(SDL_Renderer* t_renderer, TTF_Font* t_font,std::string name,  float, float);

    float m_xPos;
    float m_yPos;
    TTF_Font* m_font;
    SDL_Renderer* m_renderer;
    SDL_Rect m_imageRect;
    SDL_Rect m_textRect;
    SDL_Rect m_counterRect;
    SDL_Texture* m_image;
    SDL_Texture* m_text;
    SDL_Texture* m_clickCounter;
    std::string m_name;
    float m_buttonIncrease;
    Command* m_command;
    bool m_showCounter;
};
#endif