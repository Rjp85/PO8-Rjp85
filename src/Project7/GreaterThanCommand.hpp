#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class GreaterThanCommand : public Command
{
public:
	static int _counter;

	GreaterThanCommand(string segment = "", string arg1 = "", string arg2 = "")
		: Command(CommandType::GreaterThan, segment, arg1, arg2)
	{

	}

	virtual string ToAsm()
	{
		ostringstream result{};
		result << "@SP" << "\t\t // Start of greater than command" << endl;
		result << "M=M-1" << endl;
		result << "A=M" << endl;
		result << "D=M" << endl;
		result << "@SP" << endl;
		result << "M=M-1" << endl;
		result << "A=M" << endl;
		result << "D=M-D" << endl;
		result << "@GREATERTHANtrue" << to_string(_counter) << endl;
		result << "D;JGT" << endl;
		result << "D=0" << endl;
		result << "@GREATERTHANfalse" << to_string(_counter) << endl;
		result << "0;JMP" << endl;
		result << "(GREATERTHANtrue" << to_string(_counter) << ") " << endl;
		result << "D=-1" << endl;
		result << "(GREATERTHANfalse" << to_string(_counter) << ") " << endl;

		result << "@SP" << endl;
		result << "A=M" << endl;
		result << "M=D" << endl;
		result << "@SP" << endl;
		result << "M=M+1" << "\t\t // end of greater then command" << endl;
		_counter++;
		return result.str();


	}
};

int GreaterThanCommand::_counter = 0;