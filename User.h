#pragma once
#include <vector>
#include <string>

using namespace std;

class User {

private:
	int Id;
	string Name;
	string F_Name;
	int Year_Of_Birth;
	string Major;
	string Job_Place;
	vector<int> Connections;

public:
	// geters
	string Get_Name();
	string Get_Major();
	int Get_Id();
	string Get_F_Name();
	string Get_Job_Place();
	vector<int> Get_Connections();
	//seters
	void Set_Name(string name);
	void Set_F_Name(string f_name);
	void Set_Id(int id);
	void Set_Job_Place(string j_place);
	void Set_Major(string major);
	void Set_Year_Of_Birth(int yob);
	void Set_Connections(vector<int> ids);

	// methods

};