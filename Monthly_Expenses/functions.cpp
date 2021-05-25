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
    wallet Wallet = w[wal_ind];
    expenses e1(Category, Date, Cost, Wallet);
    if(Wallet.money - e1.cost < 0)
        cout << "There is No Enough Money Left\n";
    else {
        Wallet.money -= e1.cost;
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
                if (ex.empty())
                    cout << "No expenses to Display.\n";
                else {
                    for(int i=0; i<ex.size(); i++){
                        ex[i].display();
                    }
                }
                break;
            }

            case 2:
            {
                string filter_date;
                bool found = false;
                cout << "Enter the Date you want to filter with(dd/mm/yy): ";
                cin >> filter_date;
                for (int i = 0; i < ex.size(); i++) {
                    if (ex[i].date == filter_date)
                    {
                        ex[i].display();
                        found = true;
                    }
                }
                if (!found)
                    cout << "No data has been found.\n";
                break;
            }

            case 3:
            {
                bool found = false;
                string filter_category;
                cout << "Enter the Category you want to filter with: ";
                cin >> filter_category;
                for (int i = 0; i < ex.size(); i++) {
                    if (ex[i].category == filter_category)
                    {
                        ex[i].display();
                        found = true;
                    }
                }
                if (!found)
                    cout << "No data has been found.\n";
                break;
            }

            case 4:
            {
                bool found;
                double filter_amount;
                cout << "Enter the amount you want to filter with: ";
                cin >> filter_amount;
                for (int i = 0; i < ex.size(); i++) {
                    if (ex[i].cost == filter_amount)
                    { 
                        ex[i].display();
                        found = true;
                    }
                }
                if (!found)
                    cout << "No data has been found.\n";
                break;
            }

            case 5:
            {
                //ToDo


                break;
            }
            case 6:
            {
                int wallet_choice;
                bool found = false;
                cout << "Do you want to filter with\n1.Wallet Name\n2.Wallet Type\n";
                cout << "Choice: "; cin >> wallet_choice;

                if (wallet_choice == 1)
                {
                    string wallet_name;

                    cout << "Enter the Wallet Name: ";
                    cin >> wallet_name;

                    for (int i = 0; i < ex.size(); i++) {
                        if (wallet_name == ex[i].Wallet.name)
                        {
                            ex[i].display();
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "No data has been found.\n";
                    break;
                }
                else if (wallet_choice == 2)
                {
                    string wallet_type;

                    cout << "Enter the Wallet Type: ";
                    cin >> wallet_type;

                    for (int i = 0; i < ex.size(); i++) {
                        if (wallet_type == ex[i].Wallet.type)
                        {
                            ex[i].display();
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "No data has been found.\n";
                    break;
                }
                else
                    cout << "Invlaid Choice\n";
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
