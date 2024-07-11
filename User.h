#pragma once
#include <vector>
#include <string>

using namespace std;

class User
{

private:
	int Id;
	string Name;
	string University;
	int Year_Of_Birth;
	string Major;
	string Job_Place;
	vector<int> Connections;
	int Score;

public:
	// geters
	string Get_Name();
	string Get_Major();
	int Get_Id();
	string Get_University();
	string Get_Job_Place();
	vector<int> Get_Connections();
	int Get_Year_Of_Birth();
	int Get_Score();

	// seters
	void Set_Name(string name);
	void Set_University(string f_name);
	void Set_Id(int id);
	void Set_Job_Place(string j_place);
	void Set_Major(string major);
	void Set_Year_Of_Birth(int yob);
	void Set_Connections(vector<int> ids);
	void Set_Score(int score);

	// methods
	void Add_New_Connection(int id);
	bool Is_Connections_Empty();

	bool operator<(const User& other) const;
};
