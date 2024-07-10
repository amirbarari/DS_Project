#include <iostream>
#include <fstream>
#include "json.hpp"
#include "User.h"
#include <vector>

using json = nlohmann::json;
using namespace std;

void Read_Users_From_Json_File(string file_Path, vector<User>& Users);
void Write_Users_To_Json_File(string file_Path, vector<User>& Users);



int main()
{
	vector<User> Users;

	Read_Users_From_Json_File("inputFile.json", Users);

	for (auto u : Users)
	{
		printf("%d %s  %s\n", u.Get_Id(), u.Get_Name(), u.Get_Major());
		vector<int> con_Id = u.Get_Connections();
		for (auto c : con_Id)
			printf("%d ", c);
		printf("\n");
	}
}

void Read_Users_From_Json_File(string file_Path, vector<User>& Users)
{
	ifstream read_f(file_Path);
	if (read_f.is_open())
	{
		json json_data;
		read_f >> json_data;

		for (auto& person_data : json_data)
		{
			User user;
			user.Set_Id(person_data["ID"]);
			user.Set_Name(person_data["Name"].get<string>());
			user.Set_Year_Of_Birth(person_data["Year of Birth"]);
			user.Set_University(person_data["University"]);
			user.Set_Major(person_data["Major"]);
			user.Set_Job_Place(person_data["Job Place"]);

			for (auto& connection : person_data["Connections"])
				user.Add_New_Connection(connection);

			Users.push_back(user);
		}
	}
	else {
		printf("problem in openning file");
	}
}
