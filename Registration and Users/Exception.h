#pragma once
#include <iostream>
#include <windows.h>
#include "Time.h"

#define RED 12
#define WHITE 7

class Exception
{

protected:
	std::string text;
	unsigned short code_line;
	std::string file;
	char create_time[26];

public:

	Exception(const std::string& text, const short& code_line, const std::string& file)
	{
		Set_text(text);
		Set_code_line(code_line);
		Set_file(file);
		Set_create_time(create_time);
	}

	void Set_text(const std::string& text)
	{
		this->text = text;
	}

	std::string Get_text() const
	{
		return text;
	}

	void Set_code_line(const short& code_line)
	{
		this->code_line = code_line;
	}

	unsigned short Get_code_line() const
	{
		return code_line;
	}

	void Set_file(const std::string& file)
	{
		this->file = file;
	}

	std::string Get_file() const
	{
		return file;
	}

	const char* Get_create_time() const
	{
		return create_time;
	}

	friend std::ostream& operator << (std::ostream& out, const Exception& exception);

};

std::ostream& operator << (std::ostream& out, const Exception& exception)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);

	out << "File Name: " << exception.Get_file() << '\n';
	out << "Error Line: " << exception.Get_code_line() << '\n';
	out << "Error Explanation: " << exception.Get_text() << '\n';
	out << "Error Create Time: " << exception.Get_create_time() << "\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	return out;
}