#pragma once
#include "Registration.h"
class System
{
public:
	static void Control()
	{
		Database* data_base = new Database;
		Registration rs(data_base);

		try
		{
			rs.Sign_up("Why Guy", "Start with WHY", "Simon", "Sinek");
			rs.Sign_up("The Giant", "Nlp Master", "Anthony", "Robbins");
			rs.Sign_up("Paradigm", "Effective People 7 habits", "Stephen", "R.Covey");
			rs.Sign_up("Real Estate", "Everyone wants to go paradice but, nobody wants to die!", "Robert", "Kiyosaki");
			//data_base->Delete_user_by_id(2);
			//data_base->Delete_user_by_id(2);
			//data_base->Hash_user_data_by_id(2);
			//data_base->Hash_user_data_by_id(3);//exception
		}
		catch (const Exception& ex)
		{
			std::cout << ex << '\n';
		}

		User* user_1 = new User("Michael", "12345678", "Mike", "Nike");
		User* user_2 = new User("Antony_Band", "hsgshgshgd", "Antonio", "Banderas");


		try
		{
			data_base->Add_user(user_1);
			data_base->Show();
			data_base->Update_user(user_1, user_2);
		}
		catch (const Exception& ex)
		{
			std::cout << ex << '\n';
		}

		std::cout << "\n\n\n=============================== After Update =======================================\n\n\n";
		User* user_3 = new User("Monica Belluci", "hsgshgshgd", "Antonio", "Banderas");
		data_base->Add_user(user_3);

		data_base->Show();
	}
};