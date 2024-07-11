#include <iostream>
#include <fstream>
#include "json.hpp"
#include "User.h"
#include <vector>
#include <set>
#include <queue>


using json = nlohmann::json;
using namespace std;

// Function prototypes
void Read_Users_From_Json_File(string file_Path);
void Menu();
void get_suggestion(User u, int depth);
User get_user_By_ID(int id);
int get_weight_By_Depth(int depth);
bool Visited(int id);
void Handle_Invalid_Connections();

// Global variables
vector<User> Users;
set<int> Visited_Users;
User Selected_User;
priority_queue<User> Weights;

int main() {
    string path = "inputFile.json";
    Read_Users_From_Json_File(path);
    Handle_Invalid_Connections();
    Menu();
}

void Read_Users_From_Json_File(string file_Path) {
    ifstream read_f(file_Path);
    if (read_f.is_open()) 
    {
        json json_data;
        read_f >> json_data;
        for (auto& person_data : json_data) {
            User user;
            user.Set_Id(person_data["ID"]);
            user.Set_Name(person_data["Name"].get<std::string>());
            user.Set_Year_Of_Birth(person_data["Year of Birth"]);
            user.Set_University(person_data["University"]);
            user.Set_Major(person_data["Major"]);
            user.Set_Job_Place(person_data["Job Place"]);
            for (int connection : person_data["Connections"])
                user.Add_New_Connection(connection);
            Users.push_back(user);
        }
    }
    else
        cout << "Problem in opening the file" << std::endl;
}

void Menu() {
    int user_id;
    cout << "Enter the user ID to give him a suggestion: ";
    cin >> user_id;
    Selected_User = get_user_By_ID(user_id);
    get_suggestion(Selected_User, 0);

    cout << "5 best offers for connection:" << std::endl;
    for (int i = 0; i < 5; i++) {
        if (!Weights.empty())
        {
            User u = Weights.top();
            cout << "User with ID: " << u.Get_Id() << " | Score: " << u.Get_Score() << " | Offered to you" << std::endl;
            Weights.pop();
        }
    }
}

void get_suggestion(User user, int depth) {
    if (Visited(user.Get_Id()))
        return;
    Visited_Users.insert(user.Get_Id());

    if (depth != 0 && depth != 1) {
        int weight = get_weight_By_Depth(depth);
        if (user.Get_Major() == Selected_User.Get_Major())
            weight += 30;
        if (abs(user.Get_Year_Of_Birth() - Selected_User.Get_Year_Of_Birth()) <= 3)
            weight += 5;
        if (user.Get_University() == Selected_User.Get_University())
            weight += 15;
        if (user.Get_Job_Place() == Selected_User.Get_Job_Place())
            weight += 15;
        user.Set_Score(weight);
        Weights.push(user);
    }

    if (user.Is_Connections_Empty())
        return;
    for (auto c : user.Get_Connections()) {
        get_suggestion(get_user_By_ID(c), depth + 1);
    }
}

User get_user_By_ID(int id) {
    for (User& u : Users) {
        if (u.Get_Id() == id)
            return u;
    }
}

int get_weight_By_Depth(int depth) {
    if (depth < 5)
        return 35 - (depth * 5);
    else if (depth >= 5 && depth < 12)
        return 25 - (depth * 2);
    else
        return 10;
}

bool Visited(int id) {
    return Visited_Users.find(id) != Visited_Users.end();
}

void Handle_Invalid_Connections()
{
    for (auto& user : Users)
    {
        vector<int> valid_connections;
        for (int id : user.Get_Connections())
        {
            if (user.Get_Year_Of_Birth()  > 2006 && get_user_By_ID(id).Get_Year_Of_Birth() < 2006)
            {
            }
            else
                valid_connections.push_back(id);
        }
        user.Set_Connections(valid_connections);
    }

}
