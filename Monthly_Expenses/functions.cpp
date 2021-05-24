#include <iostream>
#include <vector>
#include "classes.cpp"
using namespace std;

vector<wallet> w;
vector<expenses> ex;

int choose_wallet()
{
    wallet w1("Default", "Cash", 1000);
    w.push_back(w1);
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
                    cout << "Wallet "<< i+1 << ": Name " << w[i].name << " of Type " << w[i].type<< endl;
                    cout << "-----------------------------------------------------------------------\n";
                }
                cout << "Press 0 to Return\n";
                cout << "Your Choice: ";        cin >> wallet_choice;
                if(wallet_choice == 0){}
                else if(wallet_choice < 0 || wallet_choice >w.size()){
                    cout << "Invalid Choice\n";
                }
                else
                    return wallet_choice-1;
            }
        }
        else if(choice ==2){
            cout << "Enter Wallet name: ";       string Name;        cin >> Name;
            cout << "Enter Wallet type: ";       string Type;        cin >> Type;
            cout << "Enter amount of money in the Wallet: ";       double Money;        cin >> Money;
            wallet w2(Name, Type, Money);
            w.push_back(w2);
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

void daily_expenses(int wal_ind)
{
    cout << "Enter The Category: ";         string Category;        cin >> Category;
    cout << "Enter The Date: ";         string Date;        cin >> Date;
    cout << "Enter The Cost: ";         double Cost;        cin >> Cost;
    expenses e1(Category, Date, Cost, wal_ind);
    if(w[wal_ind].money - e1.cost < 0)
        cout << "There is No Enough Money Left\n";
    else {
        w[wal_ind].money -= e1.cost;
        ex.push_back(e1);
    }
}

void view_expenses()
{
    int exp_choice;
    while(true)
    {
        cout << "1. View All Expenses\n";
        cout << "2. Filter By Date\n";
        cout << "3. Filter By Category\n";
        cout << "4. Filter By Amount\n";
        cout << "5. Apply Many Filters\n";
        cout << "6. Filter By Wallet\n";
        cout << "7. Exit\n";
        cout << "Your Choice: ";        cin >> exp_choice;
        switch(exp_choice)
        {
            case 1:
            {
                for(int i=0; i<ex.size(); i++){
                    ex[i].display();
                }
                break;
            }

            case 2:
            {
                //ToDo
                break;
            }

            case 3:
            {
                //ToDo
                break;
            }

            case 4:
            {
                //ToDo
                break;
            }

            case 5:
            {
                //ToDo;
                break;
            }
            case 6:
            {
                //ToDo;
                break;
            }
            case 7:
                return;
            default:
            {
                cout << "Invalid Choice\n";
            }
        }
    }

}

void view_money()
{
    int wallet_choice;
    cout << "Choose Between These Wallets\n";
    for(int i=0; i<w.size(); i++){
        cout << "Wallet "<< i+1 << ": Name " << w[i].name << " of Type " << w[i].type<< endl;
        cout << "-----------------------------------------------------------------------\n";
    }
    cout << "Your Choice: ";        cin >> wallet_choice;
    if(wallet_choice <= 0 || wallet_choice >w.size())
        cout << "Invalid Choice\n";
    else
        cout << "You Have " << w[wallet_choice-1].money << " Left in this Wallet\n";

}
