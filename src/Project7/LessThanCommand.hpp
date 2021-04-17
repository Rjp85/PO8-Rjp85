#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class LessThanCommand : public Command
{
public:
	static int _counter;

	LessThanCommand(string segment = "", string arg1 = "", string arg2 = "")
		: Command(CommandType::LessThan, segment, arg1, arg2)
	{

	}

	virtual string ToAsm()
	{
		ostringstream result{};
		result << "@SP" << "\t\t // Start of Less than command" << endl;
		result << "M=M-1" << endl;
		result << "A=M" << endl;
		result << "D=M" << endl;
		result << "@SP" << endl;
		result << "M=M-1" << endl;
		result << "A=M" << endl;
		result << "D=M-D" << endl;
		result << "@LESSTHANtrue" << to_string(_counter) << endl;
		result << "D;JLT" << endl;
		result << "D=0" << endl;
		result << "@LESSTHANfalse" << to_string(_counter) << endl;
		result << "0;JMP" << endl;
		result << "(LESSTHANtrue" << to_string(_counter) << ") " << endl;
		result << "D=-1" << endl;
		result << "(LESSTHANfalse" << to_string(_counter) << ") " << endl;

		result << "@SP" << endl;
		result << "A=M" << endl;
		result << "M=D" << endl;
		result << "@SP" << endl;
		result << "M=M+1" << "\t\t // end of Less then command" << endl;
		_counter++;
		return result.str();
	}
};

int LessThanCommand::_counter = 0;