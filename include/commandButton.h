#ifndef COMMAND_BUTTON_INCLUDE
#define COMMAND_BUTTON_INCLUDE

#include "button.h"
#include <functional>

class Game;

class CommandButton : public Button
{
public:
    CommandButton(SDL_Renderer* t_renderer, TTF_Font* t_font,  std::string t_btnName, float t_xPos, float t_yPos) :
        Button(t_renderer, t_font, t_btnName, t_xPos, t_yPos)
    {
        m_showCounter = false;
        m_undo = false;
    };

    void addFunction(std::function<void(Game*)> t_func, Game* t_caller)
    {
        m_caller = t_caller;
        m_func = t_func;
    }

    void setUndo(bool t_undo)
    {
        m_undo = t_undo;
    }

    virtual void activateButton(MacroCommand* t_macro)override
    {
        if (m_caller == nullptr && m_func == nullptr)
        {
            if (m_undo)
                t_macro->undo();
            else
                t_macro->redo();
        }
        else
        {
            m_func(m_caller);
        }
    }
private:    
    bool m_undo;
    std::function<void(Game*)> m_func;
    Game* m_caller;

};

#endif