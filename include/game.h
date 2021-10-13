#include <iostream>
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "button.h"

#include <vector>

class Game
{
public:
    Game();
    ~Game() = default;

    void init(std::string t_windowName, int t_x, int t_y, int t_width, int t_height, Uint32 t_flags);

    void handleInputs();
    void update();
    void render();

    void cleanup();

    bool isRunning();
private:

    std::vector<Button*> m_buttons;

    TTF_Font* m_gameFont;

    bool m_isRunning;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};