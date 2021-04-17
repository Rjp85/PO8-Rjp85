#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum class CommandType { Push, Pop, Add, And, Equal, GreaterThan, LessThan, Negate, Not, Or, Subtract, Label, Goto, If, Function, Return, Call };
enum class Segment { None = -1, Stack, Local, Argument, This, That, Temp, Static, Constant, Pointer, GP1 = 13, GP2, GP3 };

ostream& operator<<(ostream& os, const Segment& seg)
{
	os << (int)seg;
	return os;
}

int operator+(const Segment& seg, int num)
{
	return (int)seg + num;
}


class Command
{
private:

protected:
	string _file_name;

public:
	CommandType type;
	Segment segment;
	string arg1;
	string arg2;

	Command(CommandType type, string segment = "", string arg1 = "", string arg2 = "")
	{
		this->type = type;
		this->arg1 = arg1;
		this->arg2 = arg2;
		this->segment = Segment::None;

		if (segment == "argument")
		{
			this->segment = Segment::Argument;
		}
		else if (segment == "local")
		{
			this->segment = Segment::Local;
		}
		else if (segment == "static")
		{
			this->segment = Segment::Static;
		}
		else if (segment == "constant")
		{
			this->segment = Segment::Constant;
		}
		else if (segment == "this")
		{
			this->segment = Segment::This;
		}
		else if (segment == "that")
		{
			this->segment = Segment::That;
		}
		else if (segment == "pointer")
		{
			this->segment = Segment::Pointer;
		}
		else if (segment == "temp")
		{
			this->segment = Segment::Temp;
		}
		else if (segment == "gp1")
		{
			this->segment = Segment::GP1;
		}
		else if (segment == "gp2")
		{
			this->segment = Segment::GP2;
		}
		else if (segment == "gp3")
		{
			this->segment = Segment::GP3;
		}
	}

	void setFileName(const string& name)
	{
		_file_name = name;
	}

	string getFileName()
	{
		return _file_name;
	}

	virtual string ToAsm() = 0;
};