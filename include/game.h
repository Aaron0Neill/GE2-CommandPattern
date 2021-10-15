#ifndef GAME_INCLUDE
#define GAME_INCLUDE

#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "Buttons/baseButton.h"
#include "Command/macroCommand.h"
#include "Command/addCommand.h"
#include "Command/orderCommand.h"
#include "Command/undoMacroCommand.h"
#include "Command/executeCommand.h"
#include "Factory/factory.h"

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

    void printTotals();
private:
    void showMats();
    void handleActiveButton(float x, float y);

    std::vector<Button*> m_buttons;
    std::vector<Material*> m_mats;
    Button* m_activeButton;

    TTF_Font* m_gameFont;
    bool m_isRunning;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    MacroCommand m_commands;

    ClayFactory m_clayFactory;
    ConcreteFactory m_concreteFactory;
    WoodFactory m_woodFactory;
    LegoFactory m_legoFactory;

    SDL_Texture* m_totalsText;
    SDL_Rect m_totalsRect;
};
#endif