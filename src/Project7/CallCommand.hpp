#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class CallCommand : public Command
{
private: 
    static int counter;
public:
    CallCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::Call, segment, arg1, arg2)
    {

    }

    //function name should be in arg1
    //# arguments should be in arg2
    virtual string ToAsm()
    { 

            ostringstream result{}; 
            string returnSymbol = "returnCall" + to_string(counter);
            PushCommand localPush("pointer", "-2", "", getFileName());
            PushCommand argPush("pointer", "-1", "", getFileName());
            PushCommand thisPush("pointer", "0", "", getFileName());
            PushCommand thatPush("pointer", "1", "", getFileName());

            //PUSH return-address
            result << "@" << returnSymbol << "\t\t// Start fo Call command" << endl;
            result << "D=A" << endl;
            result << "@SP" << endl;
            result << "M=M+1" << endl;
            result << "A=M-1" << endl;
            result << "M=D" << endl;

            //PUSH lc ,arg ,this, that
            result << localPush.ToAsm() << endl; 
            result << argPush.ToAsm() << endl; 
            result << thisPush.ToAsm() << endl; 
            result << thatPush.ToAsm() << endl; 
            
            result << "@SP" << endl;
            result << "D=M" << endl;
            result << "@" << arg2 << endl;
            result << "D=D-A" << endl;
            result << "@5" << endl;
            result << "D=D-A" << endl;
            result << "@ARG" << endl;
            result << "M=D" << endl; 
            result << "@SP" << endl;
            result << "D=M" << endl;
            result << "@LCL" << endl;
            result << "M=D" << endl;
             
            result << "@" << arg1 << endl; 
            result << "(" << returnSymbol << ")\t\t// END Call command" << endl;
            counter++;
            return result.str();
        }

    };

  
