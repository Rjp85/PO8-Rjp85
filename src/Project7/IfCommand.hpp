#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class IfCommand : public Command
{
private:


public:
    IfCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::If, segment, arg1, arg2)
    {

    }

    //label to jump to should be in arg1
    virtual string ToAsm()
    { 
        ostringstream result{};
        result << "@SP" << "\t\t //Start of if-goto" << endl;
        result << "M=M-1" << endl;
        result << "A=M" << endl;
        result << "D=M" << endl;
        result << "@" << getFileName() << "." << arg1 << endl;
        result << "D;JNE" << "\t\t //end of if-goto" << endl;
         
        return result.str();
    }
};