#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Team.h"

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
    void set_player_data(Player *P);
   
    void get_data();
    
};

#endif