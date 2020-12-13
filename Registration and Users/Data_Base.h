#pragma once
#include "Data_Base_Exception.h"
#include "Invalid_Argument_Exception.h"
#include "User.h"
#include "Verification.h"

#pragma warning( disable : 4290 )

class Database
{

private:
	User** users;
	unsigned short user_count{ 0 };

public:
	void Add_user(User* const& user)
	{

		User** new_users = new User * [Get_user_count() + 1];

		for (unsigned short i = 0; i < Get_user_count(); i++)
			new_users[i] = users[i];

		delete[] users;

		new_users[Get_user_count()] = user;
		new_users[Get_user_count()]->Set_id(Get_user_count() + 1);
		User::id = Get_user_count() + 1;

		users = new_users;
		new_users = nullptr;

		Set_user_count(Get_user_count() + 1);
	}

	User*& Get_user_by_user_name(const std::string& user_name)
	{
		for (unsigned short i = 0; i < Get_user_count(); i++)
		{
			if (users[i]->Get_user_name() == user_name)
				return users[i];
		}

		User* not_found = nullptr;
		return not_found;
	}

	void Update_user(User*& old_user, User*& new_user) throw(DataBaseException, InvalidArgumentException)
	{
		if (Get_user_by_user_name(old_user->Get_user_name()) == nullptr)
			throw DataBaseException("This User Name is not in the data base!", 51, "Data_base.h");

		else if (Get_user_by_user_name(new_user->Get_user_name()) != nullptr)
			throw DataBaseException("This User Name is already exist!", 55, "Data_base.h");

		else if (Verify::Is_wrong_length_for_user_name_or_password(new_user->Get_user_name()) ||
			Verify::Is_wrong_length_for_user_name_or_password(new_user->Get_password()))
			throw InvalidArgumentException("User Name and Password must be more than 5!", 59, "Data_base.h");

		else if (Verify::Is_wrong_length_for_name_or_surname(new_user->Get_name()) ||
			Verify::Is_wrong_length_for_name_or_surname(new_user->Get_surname()))
			throw InvalidArgumentException("Name and Surname must be more than 3", 63, "Data_base.h");

		else if (Verify::Is_first_character_lowercase(new_user->Get_name()) ||
			Verify::Is_first_character_lowercase(new_user->Get_surname()))
			throw InvalidArgumentException("First character of Name and Surname must be uppercase", 67, "Data_base.h");

		

		unsigned short old_id = old_user->Get_id();

		User* user = Get_user_by_user_name(old_user->Get_user_name());
		delete user;

		user = new_user;
		user->Set_id(old_id);

		users[old_id - 1] = user;

		new_user = nullptr;
	}

	void Delete_user_by_id(const short& id)
	{
		if (Verify::Is_id_wrong(id))
			throw InvalidArgumentException("Id is invalid!", 87, "Data_base.h");

		User** new_users = new User * [Get_user_count() - 1];
		unsigned short go{ 0 };

		for (unsigned short i = 0; i + go < Get_user_count(); i++)
		{
			if (users[i]->Get_id() == id)
			{
				delete users[i];
				++go;
				--User::id;
			}

			if (i + go < user_count)
				new_users[i] = users[i + go];
		}

		for (unsigned short i = 0; i < Get_user_count() - 1; i++)
			new_users[i]->Set_id(i + 1);


		delete[] users;
		users = new_users;

		new_users = nullptr;

		Set_user_count(Get_user_count() - 1);

	}

	User*& Get_user_by_id(const short& id)
	{
		for (unsigned short i = 0; i < Get_user_count(); i++)
		{
			if (users[i]->Get_id() == id)
				return users[i];
		}

		User* not_found = nullptr;
		return not_found;

	}

	void Hash_user_data_by_id(const short& id)
	{
		if (Verify::Is_id_wrong(id))
			throw InvalidArgumentException("Id is invalid!", 134, "Data_base.h");

		else if (Verify::Is_data_hashed(Get_user_by_id(id)->Is_data_hashed()))
			throw DataBaseException("This User data is already hashed!", 137, "Data_base.h");

		User* user = Get_user_by_id(id);

		unsigned short hash_number;
		std::string hash_helper{};

		for (size_t i = 0; i < user->Get_name().length(); i++)
		{
			hash_number = (unsigned short)user->Get_name().at(i) ^ 'I';
			hash_helper += (char)hash_number;
		}

		user->Set_name(hash_helper);
		hash_helper = "";

		for (size_t i = 0; i < user->Get_surname().length(); i++)
		{
			hash_number = (unsigned short)user->Get_surname().at(i) ^ 'Q';
			hash_helper += (char)hash_number;
		}

		user->Set_surname(hash_helper);
		hash_helper = "";

		for (size_t i = 0; i < user->Get_user_name().length(); i++)
		{
			hash_number = (unsigned short)user->Get_user_name().at(i) ^ 'h';
			hash_helper += (char)hash_number;
		}

		user->Set_user_name(hash_helper);
		hash_helper = "";

		for (size_t i = 0; i < user->Get_password().length(); i++)
		{
			hash_number = (unsigned short)user->Get_password().at(i) ^ 'I';
			hash_number += (unsigned short)user->Get_password().at(i) ^ 'w';
			hash_number += (unsigned short)user->Get_password().at(i) ^ 'a';
			hash_number += (unsigned short)user->Get_password().at(i) ^ '&';
			hash_helper += (char)hash_number;
		}

		user->Set_password(hash_helper);
		user->Set_is_hashed(true);

		user = nullptr;
		std::cout << "Data is successfully Hashed!\n";
	}

	void Set_user_count(const short& user_count)
	{
		this->user_count = user_count;
	}

	unsigned short Get_user_count() const
	{
		return user_count;
	}

	void Show() const
	{
		for (unsigned short i = 0; i < Get_user_count(); i++)
		{
			std::cout << "User ID: " << users[i]->Get_id() << '\n';
			users[i]->User::Show();
		}
	}

	~Database()
	{
		for (unsigned short i = 0; i < Get_user_count(); i++)
			delete users[i];

		delete[] users;
	}

};

bool Verify::Is_wrong_length_for_user_name_or_password(const std::string& text)
{
	return (text.length() < 6);
}

bool Verify::Is_first_character_lowercase(const std::string& text)
{
	return (text[0] >= 'a' && text[0] <= 'z');
}

bool Verify::Is_wrong_length_for_name_or_surname(const std::string& text)
{
	return (text.length() < 4);
}

bool Verify::Is_id_wrong(const short& id)
{
	return (id < 0 || id > User::Get_current_id());
}

bool Verify::Is_data_hashed(const bool& is_hashed)
{
	return is_hashed;
}