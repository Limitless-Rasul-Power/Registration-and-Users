#pragma once
#include "Data_Base.h"
class Registration
{

private:
	Database* data_base;

public:

	Registration(Database* const& data_base)
	{
		if (data_base == nullptr)
			throw InvalidArgumentException("Database is nullptr", 14, "Registration.h");

		this->data_base = data_base;
	}

	void Sign_in(const std::string& user_name, const std::string& password) throw(DataBaseException)
	{
		if (data_base->Get_user_by_user_name(user_name) == nullptr)
			throw DataBaseException("This User Name didn't Exist!", 22, "Registration.h");
		else if (data_base->Get_user_by_user_name(user_name)->Get_password() != password)
			throw DataBaseException("Wrong password", 304, "Registration.h");
		else
			std::cout << "Successfully Signed in!\n";
	}

	void Sign_up(const std::string& user_name, const std::string& password, const std::string& name, const std::string& surname)
		throw(DataBaseException, InvalidArgumentException)
	{
		if (data_base->Get_user_by_user_name(user_name) != nullptr)
			throw DataBaseException("This user name is already exist please change User Name", 33, "Registration.h");

		else if (Verify::Is_wrong_length_for_user_name_or_password(user_name) ||
			Verify::Is_wrong_length_for_user_name_or_password(password))
			throw InvalidArgumentException("User Name and Password must be more than 5!", 37, "Registration.h");

		else if (Verify::Is_wrong_length_for_name_or_surname(name) ||
			Verify::Is_wrong_length_for_name_or_surname(surname))
			throw InvalidArgumentException("Name and Surname must be more than 3", 41, "Registration.h");

		else if (Verify::Is_first_character_lowercase(name) ||
			Verify::Is_first_character_lowercase(surname))
			throw InvalidArgumentException("First character of Name and Surname must be uppercase", 45, "Registration.h");

		User* new_user = new User(user_name, password, name, surname);
		data_base->Add_user(new_user);
		new_user = nullptr;
	}

	~Registration()
	{
		delete data_base;
	}

};