#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.h"

class Deck
{
private:
    vector<Card> deck;
    void generateDeck();

public:
    Deck();
    Card draw();
    void shuffle();
    void cut(int n);
    void sort();
    void printDeck();
};
#endif