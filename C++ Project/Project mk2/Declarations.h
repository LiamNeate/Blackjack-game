//Functions
#pragma once
#include <iostream>
#include <iomanip> // only used to tidy up the console output here
#include <fstream> // added file handling
#include <ctime>
#include <string>
#include <limits>
#include <thread> // for making pauses in the program
#include <chrono> // for making pauses in the program
#include <tuple>
#include <stdio.h>

using namespace std;

int main();
int fileEncryption(string fileName);
int fileDecryption(string fileName);
int Blackjack(int amm);
string* Login();
string* Register();
int* cardsGenerate();
char inputChecking(char num);
string* loginCheck(string userName);
bool passwordCheck(string password);
