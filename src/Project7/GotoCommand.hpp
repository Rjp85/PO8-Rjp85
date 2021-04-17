#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class GotoCommand : public Command
{
private:


public:
    GotoCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::Goto, segment, arg1, arg2)
    {

    }

    //label to jump to should be in arg1
    virtual string ToAsm()
    {
        ostringstream result{}; 

        if (arg1 != getFileName())
        {
            result << "@" << getFileName() << "." << arg1  << endl;
            result << "0;JMP" <<  endl;
        }
        else
        {
            result << "@" << arg1   << endl;
            result << "0;JMP"   << endl;
        }

        return result.str();
    }