#include "CardsInit.h"

CardsInit::CardsInit(int* cards, string name)
{
	username = name;
	ammCards = 5;
	availCards = 2;
	isBust = false;
	for (int i = 0; i < ammCards; i++)
	{
		cardVals[i] = cards[i];
	}
	upperCardTot = lowerCardTot = 0;
}

CardsInit::~CardsInit()
{
	/*if (ammCards > 0)
	{
		delete [] hand;
	}*/
}

int CardsInit::getHand(string fileName)
{
	ifstream inFile(fileName);
	if (!inFile)
	{
		return -1; //oh dear no file to read
	}
	hand = new Cards[ammCards];
	for (int i = 0; i < ammCards; i++)
	{
		hand[i].getHand(inFile, cardVals[i]);
		ifstream inFile(fileName);
	}
	return 0;
}

void CardsInit::Display()
{
	upperCardTot = lowerCardTot = 0;
	cout << "The "<< username <<"'s cards are " << endl;
	for (int i = 0; i < availCards; i++)
	{
		hand[i].Display();
		int tempVal = hand[i].Add();
		addTotal(tempVal);

	}
	cout << endl << "Giving " << username << " a total of " << getTotal() << endl;
}

void CardsInit::Start()
{
	upperCardTot = lowerCardTot = 0;
	for (int i = 0; i < availCards; i++)
	{
		int tempVal = hand[i].Add();
		addTotal(tempVal);

	}
}

void CardsInit::addTotal(int val)
{
	if (val == 1)
	{
		upperCardTot += 11;
	}
	else
	{
		upperCardTot += val;
	}
	lowerCardTot += val;
}

int CardsInit::getTotal()
{
	if (upperCardTot > 21)
	{
		return (lowerCardTot);
	}
	else 
	{
		return (upperCardTot);
	}
}

int CardsInit::getCardAmm()
{
	return availCards;
}

bool CardsInit::getIfBust()
{
	return isBust;
}

bool CardsInit::playBlackjack()
{
	char tempIn;
	cout << "Would you like to stick or twist (s/t) ";
	cin >> tempIn;
	char stOrTw = inputChecking(tempIn);
	if (stOrTw == 'S')
	{
		cout << endl << "Sticking!" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		return (true);
	}
	if (stOrTw == 'T')
	{
		if (availCards < ammCards)
		{
			availCards += 1;
		}
		cout << endl << "Here is your updated hand!" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		Display();
		return(getCard());
	}
	else
	{
		cout << endl << "Invalid input!" << endl;
		playBlackjack();
	}
	return(false);
}

bool CardsInit::dealerTurnBlackjack()
{
	if (getTotal()<17)
	{
		availCards += 1;
		Start();
		cout << endl << "The dealer is getting another card, meaning they have " << availCards << " cards." << endl << endl;
		this_thread::sleep_for(chrono::seconds(2));
		return(getCard());
	}
	else 
	{
		cout << endl << "Dealer is sticking!" << endl << endl;
		this_thread::sleep_for(chrono::seconds(2));
		return(true);
	}
}

bool CardsInit::getCard()
{
	if (getTotal() > 21)
	{
		isBust = true;
		//cout << "Oh no! Bust!" << endl;
		this_thread::sleep_for(chrono::seconds(2));
		return(true);
	}
	else if (getCardAmm() >= 5)
	{
		cout << "Max cards! Playing" << endl;
		this_thread::sleep_for(chrono::seconds(2));
		return(true);
	}
	return(false);
}
