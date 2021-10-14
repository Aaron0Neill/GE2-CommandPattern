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

    m_gameFont = TTF_OpenFont("assets/calibri.ttf", 20);
    if (m_gameFont == NULL)
    {
        printf("ERR\n");
    }

    updateTotals();

    m_buttons.push_back(new Button(m_renderer, m_gameFont , "Clay", 100,100));
    m_buttons.push_back(new Button(m_renderer, m_gameFont , "Concrete", 100,300));
    m_buttons.push_back(new Button(m_renderer, m_gameFont , "Wood", 400,100));
    m_buttons.push_back(new Button(m_renderer, m_gameFont , "Lego", 400,300));
    m_buttons.push_back(new CommandButton(m_renderer, m_gameFont , "Undo", 700,100));
    m_buttons.push_back(new CommandButton(m_renderer, m_gameFont , "Redo", 700,300));
    m_buttons.push_back(new CommandButton(m_renderer, m_gameFont , "Build", 1000,200));

    m_buttons.at(0)->assignCommand(new FireCommand());
    m_buttons.at(1)->assignCommand(new MixCommand());
    m_buttons.at(2)->assignCommand(new BalanceCommand());
    m_buttons.at(3)->assignCommand(new ClickCommand());
    static_cast<CommandButton*>(m_buttons.at(4))->setUndo(true);
    static_cast<CommandButton*>(m_buttons.at(6))->addFunction(Game::printTotals, this);   

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
            case SDL_MOUSEMOTION:
                handleActiveButton(event.button.x, event.button.y);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (m_activeButton != nullptr)
                {
                    m_activeButton->activateButton(&m_commands);
                    updateTotals();
                }
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

    SDL_RenderCopy(m_renderer, m_totalsText, NULL, &m_totalsRect);

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

//*********************************************

void Game::printTotals()
{
    m_commands.execute(m_mats);
    std::string s = "Built: ";
    int i =0;
    for(auto& m : m_mats)
    {
        s += m->getType() + ", ";
    }

    s = s.substr(0, s.size()-2);

    m_mats.clear();

    SDL_Surface* tempSurf = TTF_RenderText_Solid(m_gameFont, s.c_str(), SDL_Color{255,255,255});

    m_totalsText = SDL_CreateTextureFromSurface(m_renderer, tempSurf);

    SDL_QueryTexture(m_totalsText, NULL, NULL, & m_totalsRect.w, & m_totalsRect.h);

    m_totalsRect.x = 100;
    m_totalsRect.y = 500;

    SDL_FreeSurface(tempSurf);
}

//*********************************************

void Game::updateTotals()
{
    for(auto& btn : m_buttons)
    {
        btn->UpdateCounter();
    }
}