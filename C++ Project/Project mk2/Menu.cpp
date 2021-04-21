// Card game v1.1

#include "Declarations.h"
#include "User.h"

int main()
{
    char logOrReg;
    string* success;
    cout << endl << "Welcome to Liam's Casino Games!" << endl;
    while (true)
    {
        cout << endl << "Would you like to login, register or quit?(l/r/q) ";
        cin >> logOrReg;
        logOrReg = inputChecking(logOrReg);
        if (logOrReg == 'L')
        {
            success = Login();
            if (success[0] != "no")
            {
                break;
            }
        }
        else if (logOrReg == 'R')
        {
            success = Register();
            if (success[0] != "no")
            {
                break;
            }
        }
        else if (logOrReg == 'Q')
        {
            success = new string[3];
            cout << "Thanks for playing!!" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }
        else
        {
            cout << "Not a valid input! Try again" << endl << endl;
        }
    };
    if (success[2] != "")
    {
        int money = stoi(success[2]); // creating a new struct for the users info 
        User loggedInUser(success[0], success[1], money);
        loggedInUser.menu();
        main();
    }
}

char inputChecking(char num)
{
    if (num >= 'a' && num <= 'z')
    {
        num = num + 'A' - 'a';
    }
    return num;
}