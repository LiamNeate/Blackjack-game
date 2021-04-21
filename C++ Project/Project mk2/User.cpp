#include "User.h"

User::User(string name, string pass, int mon)
{
	userName = name;
	password = pass;
	money = mon;
}

User::User()
{
	money = 0;
}

void User::save()
{
    string fileName = userName + ".txt";
    ofstream newUser(fileName);
    newUser << password << "\t" << money << endl;
    newUser.close();
    fileEncryption(fileName);
}

void User::viewInfo()
{
	cout << endl << userName << "\t" << password << "\t" << money << endl;
}

void User::menu()
{
    cout << "What Would you like to do " << userName << "? " << endl;;
    char goAgain;
    bool isTrue = true;
    while (isTrue == true)
    {
        int choice = -1;
        cout << endl << "0 - Settings" << endl;
        cout << "1 - See how much money you have" << endl;
        cout << "2 - Play Blackjack" << endl;
        cout << "3 - Logout" << endl;
        cout << ": ";
        cin >> choice;
        switch (choice)
        {
        case(0):
            User::Settings();
            break;
        case(1):
            cout << endl << "You have " << money << " money!";
            break;
        case(2):
            User::setup(0);
            break;
        case(3):
            User::signOut();
            isTrue = false;
            break;
        }
    }
}

void User::signOut()
{
    cout << endl << "Logging out! ";
    userName = "";
    password = "";
    money = 0;
    this_thread::sleep_for(chrono::seconds(2));
}

void User::Settings()
{
    bool settingLoop = true;
    while (settingLoop == true)
    {
        int setChoice = -1;
        cout << endl << "Settings" << endl;
        cout << endl << "0 - Return" << endl;
        cout << "1 - Change password" << endl;
        cout << ": ";
        cin >> setChoice;
        switch(setChoice)
        {
        case(0):
            settingLoop = false;
            break;
        case(1):
            passwordChange();
        }
    }
}

void User::passwordChange()
{
    string currPass;
    string newPass;
    cout << "Please enter your current password: ";
    cin >> currPass;
    if (currPass == password)
    {
        bool success = false;
        while (success != true)
        {
            cout << endl << "Please enter a new password ((Make sure it is at least: 5 characters long; has at least one upper case and one lower case; has at least one number): ";
            cin >> newPass;
            success = passwordCheck(newPass);
        }
        cout << endl << "Password changed!";
        password = newPass;
        save();
    }
    else
    {
        cout << endl << "Not correct password! Sending back... ";
        this_thread::sleep_for(chrono::seconds(2));
    }
}

void User::setup(bool game)
{
    int amm;
    while (true)
    {
        char yOrN;
        cout << endl << "You have " << money << "! How much would you like to bet?(Only bet whole numbers!) ";
        cin >> amm;
        if (amm > money)
        {
            cout << endl << "You don't have enough money!" << endl;
        }
        else if (amm == money)
        {
            cout << endl << "You are about to go all in. Are you sure?(y/n) ";
            cin >> yOrN;
            yOrN = inputChecking(yOrN);
            cout << yOrN;
            if (yOrN == 'N')
            {
                cout << endl;
            }
            else if (yOrN != 'N' && yOrN != 'Y')
            {
                cout << "Invalid input!" << endl;
            }
        }
        else if (amm == 0)
        {
            cout << "Invalid input!" << endl;
        }
        else if (amm < money)
        {
            break;
        }
    }
    money = money - amm;
    int payout;
    payout = Blackjack(amm);
    money += payout;
    save();
    if (money == 0)
    {
        noMoney();
    }
}

void User::noMoney()
{
    cout << "Oh no!! You have ran out of money!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Reseting account back to 500..." << endl;
    money = 500;
    save();
}