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

string User::Get_University()
{
	return this->University;
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

void User::Set_University(string uni)
{
	this->University = uni;
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

void User::Add_New_Connection(int id)
{
	Connections.push_back(id);
}