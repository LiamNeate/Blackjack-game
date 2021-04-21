#include "Declarations.h"
#include "User.h"

string* Login()
{
	string* loginInfo;
	string userName = "";
	string password = "";
	cout << "Please enter your username: ";
	cin >> userName;
	cout << "Please enter your password: ";
	cin >> password;
	loginInfo = loginCheck(userName);
	if (loginInfo[1] == "" || userName == "cards") 
	{
		cout<<"User does not exist! Sending back to menu... "<<endl;
		this_thread::sleep_for(chrono::seconds(2)); //adding a wait so the use has time to read what is happening
		static string temp[3] = { "no", "no", "no" };
		return temp;
	}
	else if (loginInfo[1] != password)
	{
		cout << "Password is incorrect! Sending back to menu... " << endl;
		this_thread::sleep_for(chrono::seconds(2)); //adding a wait so the use has time to read what is happening
		static string temp[3] = { "no", "no", "no" };
		return temp;
	}
	cout << endl << "Logged in!" << endl << endl;
	return loginInfo;
}

string* loginCheck(string userName)
{
	string fileName = userName + ".txt";
	string userPassword, money;
	ifstream inFile(fileName);
	if (!inFile)
	{
		userPassword = "";
		money = "0";
	}
	else
	{
		fileDecryption(fileName);
		inFile >> userPassword;
		inFile >> money;
		fileEncryption(fileName);
	}
	string* r = new string[3];
	r[0] = userName;
	r[1] = userPassword;
	r[2] = money;
	return r;
}