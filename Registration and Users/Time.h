#pragma once
#include <ctime>
void Set_create_time(char* const& create_time)
{
	time_t now = time(NULL);
	ctime_s(create_time, 26 * sizeof(char), &now);
}
