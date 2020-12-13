#pragma once
#include "Time.h"
class User
{

private:
	unsigned short user_id;
	std::string user_name;
	std::string password;
	std::string name;
	std::string surname;
	char create_time[26];
	bool is_data_hashed;
public:

	static unsigned short id;

	User() :user_id(0), user_name(""), password(""), name(""), surname(""), create_time(""), is_data_hashed(false)
	{}

	User& operator = (const User& other)
	{
		Set_user_name(other.user_name);
		Set_password(other.password);
		Set_name(other.name);
		Set_surname(other.surname);
		memcpy(this->create_time, other.create_time, strlen(other.create_time));

		return *this;
	}


	User(const std::string& user_name, const std::string& password, const std::string& name, const std::string& surname)
	{
		Set_user_name(user_name);
		Set_password(password);
		Set_name(name);
		Set_surname(surname);
		Set_create_time(create_time);

		this->is_data_hashed = false;
	}


	void Set_id(const short& user_id)
	{
		this->user_id = user_id;
	}

	unsigned short Get_id() const
	{
		return user_id;
	}


	void Set_user_name(const std::string& user_name)
	{
		this->user_name = user_name;
	}

	std::string Get_user_name() const
	{
		return user_name;
	}


	void Set_password(const std::string& password)
	{
		this->password = password;
	}

	std::string Get_password() const
	{
		return password;
	}


	void Set_name(const std::string& name)
	{
		this->name = name;
	}

	std::string Get_name() const
	{
		return name;
	}


	void Set_surname(const std::string& surname)
	{
		this->surname = surname;
	}

	std::string Get_surname() const
	{
		return surname;
	}

	const static unsigned short Get_current_id()
	{
		return id;
	}


	void Set_is_hashed(const bool& is_hashed)
	{
		this->is_data_hashed = is_data_hashed;
	}

	bool Is_data_hashed() const
	{
		return is_data_hashed;
	}


	const char* Get_create_time() const
	{
		return create_time;
	}

	void Show() const
	{
		std::cout << "User Name: " << Get_user_name() << '\n';
		std::string x(Get_password().length(), '*');
		std::cout << "Password: " << x << '\n';
		std::cout << "Name: " << Get_name() << '\n';
		std::cout << "Surname: " << Get_surname() << '\n';
		std::cout << "Created Time: " << Get_create_time() << "\n\n";
	}

};