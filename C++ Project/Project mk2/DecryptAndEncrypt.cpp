#include "Declarations.h"
// code inspider by codescracker.com
int fileEncryption(string fileName)
{
    char ch;
    ifstream login(fileName); //opening login file in read only
    if (!login) // chekcing if file exists
    {
        cout << endl << "Error Occurred, Opening the Source File (to Read)!" << endl;
        return 0;
    }
    ofstream key("tmp"+fileName+".txt"); //opens file in writing mode. Means that if no file exists, can create one
    if (!key) // creating a temp storage file for the encrypted data
    {
        cout << endl << "Error Occurred, Opening/Creating the tmp File!" << endl;
        return 0;
    }
    while (login >> noskipws >> ch) // reading each character letter by letter, including white space, form the file
    {
        ch = ch + 100; // adding a value of 100 to each character so that it becomes encrypted, and storing in temp file
        key << ch;
    }
    login.close(); // closes all files
    key.close();
    ofstream login1(fileName); // re-opening the original data file in write mode
    if (!login1)
    {
        cout << endl << "Error Occurred, Opening the Source File (to write)!" << endl;
        return 0;
    }
    ifstream key1("tmp" + fileName + ".txt"); // re-opening the encrypted message file in read mode
    if (!key1)
    {
        cout << endl << "Error Occurred, Opening the tmp File!" << endl;
        return 0;
    }
    while (key1 >> noskipws >> ch)
    {
        login1 << ch; // storing each char from the temp file into the data file
    }
    login1.close();
    key1.close();
    return 0;
}

// code inspider by codescracker.com
int fileDecryption(string fileName) // doing the reverse of encyption
{
    char ch;
    ofstream login(fileName);
    if (!login)
    {
        cout << endl << "Error Occurred while Opening the Source File!" << endl;
        return 0;
    }
    ifstream key("tmp" + fileName + ".txt");
    if (!key)
    {
        cout << endl << "Error Occurred while Opening/Creating tmp File!" << endl;
        return 0;
    }
    while (key >> noskipws >> ch)
    {
        ch = ch - 100;
        login << ch;
    }
    login.close();
    key.close();
    return 0;
}