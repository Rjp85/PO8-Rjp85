#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class NegateCommand : public Command
{
public:
    NegateCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::Negate, segment, arg1, arg2)
    {

    }
	virtual string ToAsm()
	{
        ostringstream result{};
        result << "@SP" << "\t\t //start of NEGATE command" << endl;
        result << "M=M-1 " << endl;
        result << "A=M" << endl;
        result << "M=-M" << "\t\t //end negate command" << endl;
        result << "@SP" << endl;
        result << "M=M+1" << endl;
        return result.str();
	}
}; 