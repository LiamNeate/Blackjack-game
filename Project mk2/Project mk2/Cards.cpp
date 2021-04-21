#include "Cards.h"
#include "Declarations.h"

Cards::Cards(int val, string disp, string ty)
{
    Value = val;
    DisplayValue = disp;
    Type = ty;
}

Cards::Cards()
{
    Type = "None";
    //userUpperCardTot = userLowerCardTot = dealerUpperCardTot = dealerLowerCardTot = 0;
}

void Cards::getHand(ifstream& cardsStore, int cardValue)
{
    //learnt from stack overflow, reads through whole file, ignores all lines until the
    //line with the specific card is read
    cardsStore.seekg(ios::beg);
    for (int i = 0; i < (cardValue - 1); ++i)
    {
        cardsStore.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cardsStore >>DisplayValue>>Value>>Type;
}

void Cards::Display()
{
    cout << DisplayValue << " " << Type << endl;
}

int Cards::Add()
{
    return Value;
}