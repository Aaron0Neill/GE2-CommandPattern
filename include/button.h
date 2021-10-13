#ifndef BUTTON_INCLUDE
#define BUTTON_INCLUDE

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <cstdio>

class Button
{
public:
    Button(SDL_Renderer* t_renderer, TTF_Font* t_font,  std::string t_btnName, float t_xPos, float t_yPos);
    ~Button();
    void draw();

    

private:
    SDL_Renderer* m_renderer;
    SDL_Rect m_imageRect;
    SDL_Rect m_textRect;
    SDL_Texture* m_image;
    SDL_Texture* m_text;
    std::string m_name;
};
#endif