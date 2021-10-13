#include "../include/game.h"

Game::Game() : 
    m_isRunning(true)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
}

//*********************************************

void Game::init(std::string t_windowName, int t_x, int t_y, int t_width, int t_height, Uint32 t_flags)
{
    m_window = SDL_CreateWindow(t_windowName.c_str(), t_x, t_y, t_width, t_height, t_flags);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    m_gameFont = TTF_OpenFont("assets/calibri.ttf", 32);
    if (m_gameFont == NULL)
    {
        printf("ERR\n");
    }

    m_buttons.push_back(new Button(m_renderer, m_gameFont , "Clay", 100,100));
    m_buttons.push_back(new Button(m_renderer, m_gameFont , "Concrete", 100,300));
    m_buttons.push_back(new Button(m_renderer, m_gameFont , "Wood", 400,100));
    m_buttons.push_back(new Button(m_renderer, m_gameFont , "Lego", 400,300));

    m_buttons.at(3)->assignCommand(new ClickCommand());

    m_activeButton = m_buttons.at(0);
    m_activeButton->onHover();
}

//*********************************************

void Game::handleInputs()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                m_isRunning = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == 'w')
                    showMats();
                break;
            case SDL_MOUSEMOTION:
                handleActiveButton(event.button.x, event.button.y);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (m_activeButton != nullptr)
                    m_activeButton->activateButton(m_mats);
                break;
            case SDL_MOUSEBUTTONUP:
                break;
        }
    }
}

//*********************************************

void Game::update()
{
}

//*********************************************

void Game::render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 255,255,255,255);

    for(auto& btn : m_buttons)
        btn->draw();

    SDL_RenderPresent(m_renderer);
}

//*********************************************

void Game::cleanup()
{
    SDL_DestroyWindow(m_window);
    std::cout << "Finished Cleaning\n";
}

//*********************************************

bool Game::isRunning()
{
    return m_isRunning;
}

//*********************************************

void Game::showMats()
{
    for(auto& mat : m_mats)
    {
        std::cout << mat->getType() << std::endl;
    }
}

//*********************************************

void Game::handleActiveButton(float x, float y)
{
    bool noHover = false;
    for(auto& btn : m_buttons)
    {
        if (btn->contains(x,y))
        {
            if (m_activeButton != nullptr)
                m_activeButton->loseHover();

            m_activeButton = btn;
            m_activeButton->onHover();
            noHover = true;
        }
    }

    if (!noHover)
        if (m_activeButton != nullptr)
        {
            m_activeButton->loseHover();
            m_activeButton = nullptr;
        }   
}