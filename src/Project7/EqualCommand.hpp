#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class EqualCommand : public Command
{
public:
	static int _counter;

	EqualCommand(string segment = "", string arg1 = "", string arg2 = "")
		: Command(CommandType::Equal, segment, arg1, arg2)
	{

	}

	virtual string ToAsm()
	{
		ostringstream result{};
		result << "@SP" << "\t\t // start of EQUAL command" << endl;
		result << "M=M-1" << endl;
		result << "A=M" << endl;
		result << "D=M" << endl;
		result << "@SP" << endl;
		result << "M=M-1" << endl;
		result << "A=M" << endl;
		result << "D=M-D" << endl;
		result << "@EQUAL" << to_string(_counter) << endl;
		result << "D;JEQ" << endl;
		result << "D=1" << endl;

		result << "(EQUAL" << to_string(_counter) << ") " << endl;
		result << "D=D-1" << endl;
		result << "@SP" << endl;
		result << "A=M" << endl;
		result << "M=D" << endl;
		result << "@SP" << endl;
		result << "M=M+1" << "\t\t // end of equal command" << endl;

		_counter++;
		return result.str();
	}
};

int EqualCommand::_counter = 0;