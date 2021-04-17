#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class ReturnCommand : public Command
{
private:


public:
    ReturnCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::Return, segment, arg1, arg2)
    {

    }

    virtual string ToAsm()
    {
        ostringstream result{};
        //sending frame to LCL pointer localtion
        result << "@LCL" << "\t\t //begining of the return command" << endl;
        result << "D=M" << endl;
        result << "@FRAME" << endl;
        result << "M=D" << endl;
        //putting label-address in a temp location 
        result << "@5" << endl;
        result << "D=A" << endl;
        result << "@FRAME" << endl;
        result << "A=M-D" << endl;
        result << "D=M" << endl;
        result << "@RET" << endl;
        result << "M=D" << endl;
        //repositioning the return value for the caller
        result << "@SP" << endl;
        result << "AM=M-1" << endl;
        result << "D=M" << endl;
        result << "@ARG" << endl;
        result << "A=M" << endl;
        result << "M=D" << endl;
        //restore Sp
        result << "@ARG" << endl;
        result << "D=M+1" << endl;
        result << "@SP" << endl;
        result << "M=D" << endl;
        //restore that
        result << "@1" << endl;
        result << "D=A" << endl;
        result << "@FRAME" << endl;
        result << "A=M-D" << endl;
        result << "D=M" << endl;
        result << "@THAT" << endl;
        result << "M=D" << endl;
        //restore this
        result << "@2" << endl;
        result << "D=A" << endl;
        result << "@FRAME" << endl;
        result << "A=M-D" << endl;
        result << "D=M" << endl;
        result << "@THIS" << endl;
        result << "M=D" << endl;
        //restore arg
        result << "@3" << endl;
        result << "D=A" << endl;
        result << "@FRAME" << endl;
        result << "A=M-D" << endl;
        result << "D=M" << endl;
        result << "@ARG" << endl;
        result << "M=D" << endl;
        //restore LCL
        result << "@4" << endl;
        result << "D=A" << endl;
        result << "@FRAME" << endl;
        result << "A=M-D" << endl;
        result << "D=M" << endl;
        result << "@LCL" << endl;
        result << "M=D" << endl;
        //goto return localtion 
        result << "@RET" << endl;
        result << "A=M" << endl;
        result << "0;JMP" << endl;
        return result.str();
    }
};