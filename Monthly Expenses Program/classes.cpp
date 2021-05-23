#pragma once
#include <iostream>
using namespace std;

class expenses{
public:
    string category;
    string date;
    double amount;
    int wallet_index;

    expenses(string c, string d, double a, int w_i){
        category = c;
        date = d;
        amount = a;
        wallet_index = w_i;
    }
    void display(){
        cout << "You spent " << amount << " in " << category << " on " << date << endl;
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
    double remaining_money();
    ~wallet(){}
};
