 #pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class AndCommand : public Command
{
public:
    AndCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::And, segment, arg1, arg2)
    {

    }

    virtual string ToAsm()
    { 

        ostringstream result{};
        result << "@SP" << "\t\t //start of AND command" << endl;
        result << "M=M-1" << endl;
        result << "A=M" << endl;
        result << "D=M" << endl;
        result << "A=A-1" << endl;
        result << "M=D&M" << "\t\t //end of AND command" << endl; 
	}
};