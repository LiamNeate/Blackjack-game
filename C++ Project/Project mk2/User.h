#pragma once
#include "Declarations.h"

struct User
{
public:
	User(string name, string pass, int mon);
	User();
	void viewInfo();
	void menu();
	void setup(bool game);
	void Settings();
	void save();
	void signOut();
	void passwordChange();
	void noMoney();
private:
	string userName;
	string password;
	int money;
};
