#include "Declarations.h"
#include "User.h"

string* Register() 
{
	string userName;
	string password;
	cout << "Please enter a username: ";
	cin >> userName;
	string* loginInfo = loginCheck(userName);
	if (loginInfo[1] != "")
	{
		cout << "User already exists! Sending back to menu... " << endl;
		this_thread::sleep_for(chrono::seconds(1)); //adding a wait so the use has time to read what is happening
		loginInfo[0] = "no";
		return loginInfo;
	}
	bool passwordSuccess = false;
	while (passwordSuccess != true)
	{
		cout << "Please enter a password (Make sure it is at least: 5 characters long; has at least one upper case and one lower case; has at least one number): ";
		cin >> password;
		passwordSuccess = passwordCheck(password);
	}
	User loggedInUser(userName, password, 500);
	loggedInUser.save();
	cout << "User Created!" << endl;
	string* newLoginInfo = loginCheck(userName);
	return newLoginInfo;
}

bool passwordCheck(string password)
{
	bool isUpper = false, isLower = false, isSpecial = false, isNum = false;
	if (password.length() < 5)
	{
		cout << endl << "Password not long enough!" << endl;
		return false;
	}
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] >= 'a' && password[i] <= 'z')
		{
			isLower = true;
		}
		else if (password[i] >= 'A' && password[i] <= 'Z')
		{
			isUpper = true;
		}
		else if (password[i] >= '0' && password[i] <= '9')
		{
			isNum = true;
		}
		else
		{
			isSpecial = true;
		}
	}
	if (isUpper == true && isLower == true && isSpecial == true && isNum == true)
	{
		return true;
	}
	cout << endl << "Does not meet specific letter criteria! " << endl;
	return false;
}