#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class FunctionCommand : public Command
{
private:


public:
    FunctionCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::Return, segment, arg1, arg2)
    {

    }

    //function name should be in arg1
    //# arguments should be in arg2
    virtual string ToAsm()
    {
        ostringstream result{};
        result << "(" << arg1 << ")" <<  endl;
        //sets all local variables arguments to zero
        for (int i = 0; i < stoi(arg2); i++)
        {
            result << "@0" << endl;
            result << "D=A" << endl;
            result << "@SP" << endl;
            result << "A=M" << endl;
            result << "M=D" << endl;
            result << "@SP" << endl;
            result << "M=M+1" << endl;
        }
        return result.str();
    }
};