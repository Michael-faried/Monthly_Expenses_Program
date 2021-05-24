#pragma once
#include <iostream>
using namespace std;

class expenses{
public:
    string category;
    string date;
    double cost;
    int wallet_index;

    expenses(string cat, string d, double c, int w_i){
        category = cat;
        date = d;
        cost = c;
        wallet_index = w_i;
    }
    void display(){
        cout << "You spent " << cost << " in " << category << " on " << date << endl;
    }
    ~expenses(){}
};

class wallet{
public:
    string name;
    string type;
    double money;

    wallet(string n, string t, double m){
        name = n;
        type = t;
        money = m;
    }
    ~wallet(){}
};
