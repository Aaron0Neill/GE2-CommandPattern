#ifndef UNDO_MACRO_COMMAND_INCLUDE
#define UNDO_MACRO_COMMAND_INCLUDE

#include "Command/macroCommand.h"

class UndoMacroCommand : public Command
{
public:
    UndoMacroCommand(MacroCommand* t_macro) :
        m_macro(t_macro){}

    void execute()
    {
        m_macro->undo();
    }

    void undo()override
    {
        m_macro->addLastCommand();
    }

private:
    MacroCommand* m_macro;
};

#endif