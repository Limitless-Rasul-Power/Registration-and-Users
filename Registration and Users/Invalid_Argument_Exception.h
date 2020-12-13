#pragma once
#include "Exception.h"
class InvalidArgumentException : public Exception
{
public:
	InvalidArgumentException(const std::string& text, const short& code_line, const std::string& file)
		:Exception(text, code_line, file)
	{}
};