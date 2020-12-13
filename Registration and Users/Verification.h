#pragma once
#include <string>
class Verify
{
public:

	static bool Is_wrong_length_for_user_name_or_password(const std::string& text);

	static bool Is_first_character_lowercase(const std::string& text);

	static bool Is_wrong_length_for_name_or_surname(const std::string& text);

	static bool Is_id_wrong(const short& id);

	static bool Is_data_hashed(const bool& is_hashed);

};