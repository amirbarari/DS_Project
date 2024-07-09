#include "User.h"

string User::Get_Name()
{
	return this->Name;
}

string User::Get_Major()
{
	return this->Major;
}

int User::Get_Id()
{
	return this->Id;
}

string User::Get_F_Name()
{
	return this->F_Name;
}

string User::Get_Job_Place()
{
	return this->Job_Place;
}

vector<int> User::Get_Connections()
{
	return this->Connections;
}

void User::Set_Name(string name)
{
	this->Name = name;
}

void User::Set_F_Name(string f_name)
{
	this->F_Name = f_name;
}

void User::Set_Id(int id)
{
	this->Id = id;
}

void User::Set_Job_Place(string j_place)
{
	this->Job_Place = j_place;
}

void User::Set_Major(string major)
{
	this->Major = major;
}

void User::Set_Year_Of_Birth(int yob)
{
	this->Year_Of_Birth = yob;
}

void User::Set_Connections(vector<int> ids)
{
	this->Connections = ids;
}
