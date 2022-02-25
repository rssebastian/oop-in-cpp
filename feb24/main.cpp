#include <iostream>
#include "Deck.h"

using namespace std;

int main()
{
    Deck deck;
    deck.printDeck();
    cout << "-----------Cutting the deck--------------\n";
    deck.cut(50);
    deck.printDeck();
    return 0;
}