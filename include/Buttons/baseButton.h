#ifndef BASE_BUTTON_INCLUDE
#define BASE_BUTTON_INCLUDE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Command/baseCommand.h"

class Button
{
public:
    Button(SDL_Renderer* t_renderer, TTF_Font* t_ttf, std::string t_btnName, float t_xPos, float t_yPos);
    ~Button();

    void addCommand(Command* t_command) { m_command = t_command; };

    virtual void activateButton();

    virtual void undoButton();

    virtual void onHover();

    virtual void loseHover();

    virtual bool contains(float xPos, float yPos);

    void draw(SDL_Renderer* t_renderer);

    int& getCount() { return m_count; }

    void setCount(int t_count) {m_count = t_count;}

    void setShowing(bool t_show) { m_showCount = t_show;}

    void updateCounter(SDL_Renderer* t_renderer, TTF_Font* t_ttf);
private:

    void initButtonTexture(SDL_Renderer* t_renderer);

    void initButtonText(SDL_Renderer* t_renderer, TTF_Font* t_ttf, std::string t_btnName);

    SDL_Rect m_textRect;
    SDL_Rect m_textureRect;
    SDL_Rect m_counterRect;
    SDL_Texture* m_buttonTexture;
    SDL_Texture* m_buttonText;
    SDL_Texture* m_buttonCounter;
    Command* m_command;
    float m_sizeIncrease;
    int m_count;
    bool m_showCount;
};

#endif