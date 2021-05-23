#include <iostream>
#include <vector>
#include "classes.cpp"
using namespace std;

vector<wallet> w;
vector<expenses> ex;

int choose_wallet()
{
    int choice;
    while (true)
    {
        int wallet_choice;
        cout << "Choose a Wallet\n";
        cout << "1. Existing Wallet\n";
        cout << "2. New Wallet\n";
        cout << "Your Choice: ";     cin >> choice;
        if(choice == 1){
            if(w.empty())
                cout << "No Wallets to display\n";
            else{
                cout << "Choose Between These Wallets\n";
                for(int i=0; i<w.size(); i++){
                    cout << "Wallet "<< i+1 << ": Name " << w[i].name << " of Type " << w[i].type<< " Contains " << w[i].money << endl;
                    cout << "-----------------------------------------------------------------------\n";
                }
                cout << "Your Choice: ";        cin >> wallet_choice;
                return wallet_choice-1;
            }
        }
        else if(choice ==2){
            cout << "Enter Wallet name: ";       string Name;        cin >> Name;
            cout << "Enter Wallet type: ";       string Type;        cin >> Type;
            cout << "Enter amount of money in the Wallet: ";       double Money;        cin >> Money;
            wallet w1(Name, Type, Money);
            w.push_back(w1);
            return (w.size())-1;
        }
        else
            cout << "Invalid Choice\n";
    }
}


void monthly_income(int wal_ind)
{
    cout << "Enter Your Monthly Income: ";
    int mon_income;      cin >> mon_income;
    w[wal_ind].money += mon_income;
    cout << "This Wallet now contains: " << w[wal_ind].money << " Dollars\n";
}
