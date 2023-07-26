#include <iostream>

#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Player
{
private:
    string firstName;
    string lastName;
    unsigned int jer_Num;
    bool active_Status;
    static vector<string> players_name;
    static vector<int> players_jersey;

public:
    void set_player_data(Player *P)
    {
        fflush(stdin);
        cout << "Enter First name of the Player: ";
        getline(cin, P->firstName);
        fflush(stdin);
        cout << "Enter Last name of the Player: ";
        getline(cin, P->lastName);
        P->jer_Num = rand() % 100;
    re_enter:
        cout << "Select the Active Status(1/0): ";
        cin >> P->active_Status;
        if (active_Status > 1 || active_Status < 0)
        {
            cout << "Wrong Input\nRe-Enter the Status";
            goto re_enter;
        }
        string fullName = firstName + " " + lastName;
        players_name.push_back(fullName);
        players_jersey.push_back(jer_Num);
    }
    void get_data()
    {
        for (auto i = 0; i < players_name.size(); i++)
        {
            cout << players_jersey[i] << "   " << players_name[i] << endl;
        }
    }
};
vector<int> Player::players_jersey;
vector<string> Player::players_name;
class Team
{
private:
    string location;
    string nickName;
    Player player;
    bool flag = false;
    static vector<string> team_names;

public:
    Team set_team_data(Team *T)
    {
        fflush(stdin);
        cout << "Enter Team location: ";
        getline(cin, T->location);
        fflush(stdin);
        cout << "Enter Team Nickname: ";
        getline(cin, T->nickName);
        if (team_names.size() == 0)
        {
            team_names.push_back(nickName);
        }
        else
        {
            for (auto i = 0; i < team_names.size(); i++)
            {
                if (team_names[i] == T->nickName)
                {
                    flag = true;
                }
            }
            if (flag)
            {
                cout << "---Team Already Exist Cannot create this team.---\n";
            }
            else
            {
                team_names.push_back(nickName);
            }
        }
        return *T;
    }
    void add_player(Team *T)
    {
        string n_name;
        char name;
        Player playr;
        bool flag = false;
        cout << "Enter the Team Nickname: ";
        cin >> n_name;
        for (auto i = 0; i < team_names.size() - 1; i++)
        {
            if (n_name != team_names[i])
            {
                flag = true;
            }
            else
            {
                playr.set_player_data(&playr);
            }
        }
        if (flag)
        {
            cout << "---Cannot Enter Player Details Team Doesn't Exist---\n";
        }
    }
    void get_teams()
    {
        for (auto i = 0; i < team_names.size(); i++)
        {
            cout << "#" << i + 1 << " Team: " << team_names[i] << endl;
        }
    }
    void get_player()
    {
        Player playr;
        string n_name;
        cout << "Enter the Team Nickname: ";
        cin >> n_name;
        for (auto i = 0; i < team_names.size() - 1; i++)
        {
            if (n_name != team_names[i])
            {
                flag = true;
            }
            else
            {
                playr.get_data();
            }
        }
    }
};
vector<string> Team ::team_names;
int main()
{
    Team team;
    Player playr;
    int choice = 0, again;
    while (choice != 5)
    {
        cout << "Choose from the following:\n1. Team\n2. Player\n3. League\n4. Roster\n5. Quit\n";
        cin >> choice;
        if (choice < 1 || choice > 5)
        {
            cout << "Wrong Choice Entered\n";
        }
        else if (choice == 1)
        {
            team = team.set_team_data(&team);
        }
        else if (choice == 2)
        {
            team.add_player(&team);
        }
        else if (choice == 3)
        {
            team.get_teams();
        }
        else if (choice == 4)
        {
            team.get_player();
        }
        else if (choice == 5)
        {
            cout << "\nBYE\n";
        }
    }
}
