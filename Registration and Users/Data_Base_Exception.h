#pragma once
#include "Exception.h"
class DataBaseException : public Exception
{
public:
	DataBaseException(const std::string& text, const short& code_line, const std::string& file)
		:Exception(text, code_line, file)
	{}
};