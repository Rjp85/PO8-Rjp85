#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class NotCommand : public Command
{
public:
    NotCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::Not, segment, arg1, arg2)
    {

    }

    virtual string ToAsm()
    {
        ostringstream result{};
        result << "@SP" << "\t\t //Start of Not command " << endl;
        result << "A=M" << endl;
        result << "A=A-1" << endl;
        result << "M=!M" << "\t\t //end of not commmand" << endl;
        return result.str();
    }
};