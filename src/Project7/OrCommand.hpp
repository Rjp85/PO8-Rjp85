#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class OrCommand : public Command
{
public:
    OrCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::Or, segment, arg1, arg2)
    {

    }

    virtual string ToAsm()
    {
        ostringstream result{};
        result << "@SP" << "\t\t // Start of OR command" << endl;
        result << "M=M-1" << endl;
        result << "A=M" << endl;
        result << "D=M" << endl;
        result << "A=A-1" << endl;
        result << "M=D|M" << "\t\t //end of or command" << endl;
        return result.str();
    }
};