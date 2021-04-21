#include "Declarations.h"
#include "CardsInit.h"

// extra function here as couldn't seem to get it to work when put with the other functions
int winOrLose(CardsInit userhand, CardsInit dealerhand);

int Blackjack(int amm)
{
	int option;
	cout << "======================" << endl;
	cout << "Welcome to Blackjack!" << endl;
	cout << "======================" << endl << endl;
	bool check = true;
	while (check == true)
	{
		cout << "What would you like to do? " << endl;
		cout << "0 - View rules" << endl;
		cout << "1 - View payout" << endl;
		cout << "2 - Play blackjack" << endl;
		cout << ": ";
		cin >> option;
		switch (option)
		{
		case(0):
			cout << endl << "The goal of blackjack is to beat the dealer's hand without going over 21." << endl;
			cout << "Face cards are worth 10. Aces are worth 1 or 11, whichever makes a better hand." << endl;
			cout << "The player and the dealer both start with 2 cards." << endl;
			cout << "To 'Twist' is to ask for another card. To 'Stick' is to hold your total and end your turn." << endl;
			cout << "If you go over 21 you bust and cannot get anymore cards." << endl;
			cout << "If you and the dealer have the same number, or are both bust, you get your money back." << endl;
			cout << "If you are dealt 21 from the start(Ace & 10), you got a blackjack." << endl;
			cout << "Dealer will hit until their cards total 17 or higher." << endl << endl;
			break;
		case(1):
			cout << endl << "A win gives you 1x, while a blackjack gives you 1.5x!" << endl << endl;
			break;
		case(2):
			check = false;
			break;
		}
	}
	cout << "Dealing out the hands..." << endl << endl;
	int* totalCards = cardsGenerate();
	int userCardVals[5];
	int dealerCardVals[5];
	for (int i = 0; i < 5; i++)
	{
		userCardVals[i] = totalCards[i];
		dealerCardVals[i] = totalCards[i + 5];
	}
	CardsInit userhand(userCardVals, "User");
	CardsInit dealerhand(dealerCardVals, "Dealer");
	userhand.getHand("cards.txt");
	dealerhand.getHand("cards.txt");
	bool endTurn = false;
	bool dealerEndTurn = false;
	userhand.Display();
	dealerhand.Start();
	while (endTurn == false || dealerEndTurn == false)
	{
		if (endTurn == false)
		{
			endTurn = userhand.playBlackjack();
		}
		if (dealerEndTurn == false)
		{
			dealerEndTurn = dealerhand.dealerTurnBlackjack();
		}
	}
	int winner = winOrLose(userhand, dealerhand);
	switch (winner)
	{
	case(0):
		if (userhand.getCardAmm() == 2 && userhand.getTotal() == 21)
		{
			cout << endl << "Blackjack! You won " << (amm * 2.5) << "! Returning to menu." << endl;
			this_thread::sleep_for(chrono::seconds(2));
			return (amm * 2.5);
		}
		cout << endl << "Well done! You won " << (amm * 2) << "! Returning to menu." << endl;
		this_thread::sleep_for(chrono::seconds(2));
		return (amm * 2);
	case(1):
		cout << endl << "Oh no! You lost " << (amm) << "! Returning to menu." << endl;
		this_thread::sleep_for(chrono::seconds(2));
		return (0);
	case (2):
		cout << endl << "A tie! You get " << (amm) << " back! Returning to menu." << endl;
		this_thread::sleep_for(chrono::seconds(2));
		return(amm);
	}
}

int winOrLose(CardsInit userhand, CardsInit dealerhand)
{
	cout << endl << endl << "Showing cards!" << endl << "===============" << endl;
	userhand.Display();
	cout << endl;
	dealerhand.Display();
	if ((userhand.getTotal() > dealerhand.getTotal())&&(userhand.getIfBust()==false)||((userhand.getIfBust()==false)&&(dealerhand.getIfBust() == true)))
	{
		cout << "User wins!" << endl;
		return(0);
	}
	else if ((userhand.getTotal() < dealerhand.getTotal()) && (dealerhand.getIfBust() == false) || ((userhand.getIfBust() == true) && (dealerhand.getIfBust() == false)))
	{
		cout << "Dealer wins!" << endl;
		return(1);
	}
	else 
	{
		cout << "No winner!" << endl;
		return(2);
	}
}

int* cardsGenerate()
{
	srand((unsigned)time(NULL));
	static int r[10];
	for (int i = 0; i < 10; ++i)
	{
		r[i] = (rand() % 52);
	}
	bool anyDupes = true;
	while (anyDupes == true)
	{
		anyDupes = false;
		for (int j = 0; j < 10; ++j)
		{
			for (int k = (1 + j); k < 10; ++k)
			{
				if (r[j] == r[k])
				{
					r[k] = (rand() % 52);
					anyDupes = true;
				}
			}
		}
	}
	return r;
}