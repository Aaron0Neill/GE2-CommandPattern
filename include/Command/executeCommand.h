#ifndef EXECUTE_COMMAND_INCLUDE
#define EXECUTE_COMMAND_INCLUDE

#include "Command/macroCommand.h"
#include <functional>

class Game;

class ExecuteCommand : public Command
{
public:
    ExecuteCommand(MacroCommand* t_macro, std::function<void(Game*)> t_func, Game* t_game) : 
        m_macro(t_macro), m_func(t_func), m_game(t_game) {}

    void execute()override
    {
        m_macro->execute();
        m_func(m_game);
    }

    void undo()override
    {
        printf("It can not be undone\n");
    }
private:
    MacroCommand* m_macro;
    std::function<void(Game*)> m_func;
    Game* m_game;
};
#endif