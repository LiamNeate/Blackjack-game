#pragma once
#include "Declarations.h"

class Cards
{
public:
	Cards(int val, string disp, string ty);
	Cards();
	void getHand(ifstream& cardsStore, int cardValue);
	void Display();
	int Add();
private:
	int Value; //The ammount a card is worth i.e. King would be 11
	string DisplayValue; //The value will be displayee i.e 2 or K
	string Type; //The suit it is
};