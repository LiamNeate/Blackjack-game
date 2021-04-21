#pragma once
#include "Cards.h"

struct CardsInit
{
public:
	CardsInit(int* cards, string name);
	~CardsInit();
	int getHand(string fileName);
	int getTotal();
	int getCardAmm();
	void addTotal(int val);
	bool playBlackjack();
	bool dealerTurnBlackjack();
	void Display();
	void Start();
	bool getCard();
	bool getIfBust();
private:
	Cards* hand;
	string username;
	int ammCards;
	int cardVals[5];
	int availCards;
	int upperCardTot;
	int lowerCardTot;
	bool isBust;
};