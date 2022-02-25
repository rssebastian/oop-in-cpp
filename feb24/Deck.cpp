#include "Deck.h"
#include "Card.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

bool sortBySuit(Card &card1, Card &card2);

Deck::Deck()
{
    generateDeck();
    shuffle();
    cout << "Deck generated and shuffled!\n";
}

void Deck::shuffle()
{
    srand(time(0));
    vector<Card> shuffledDeck;
    while (!deck.empty())
    {
        int card = rand() % deck.size();
        shuffledDeck.push_back(deck.at(card));
        deck.erase(deck.begin() + card);
    }
    deck = shuffledDeck;
}

Card Deck::draw()
{
    Card card = deck.at(0);
    deck.erase(deck.begin());
    return card;
}

void Deck::cut(int n)
{
    int cardsToMove = deck.size() - n;
    while (cardsToMove != 0)
    {
        Card bottomOfDeck = deck.back();
        deck.insert(deck.begin(), bottomOfDeck);
        deck.pop_back();
        cardsToMove--;
    }
}

// void Deck::sort()
// {
//     sort(deck.begin(), deck.end(), sortBySuit);
//     sort()
// }

void Deck::generateDeck()
{
    for (int suit = 0; suit < NUMSUITS; suit++)
    {
        for (int rank = 0; rank < NUMRANKS; rank++)
        {
            Suit cardSuit;
            Rank cardRank;

            switch (suit)
            {
            case 0:
                cardSuit = SPADES;
                break;
            case 1:
                cardSuit = HEARTS;
                break;
            case 2:
                cardSuit = DIAMONDS;
                break;
            case 3:
                cardSuit = CLUBS;
                break;
            }

            switch (rank)
            {
            case 0:
                cardRank = ACE;
                break;
            case 1:
                cardRank = TWO;
                break;
            case 2:
                cardRank = THREE;
                break;
            case 3:
                cardRank = FOUR;
                break;
            case 4:
                cardRank = FIVE;
                break;
            case 5:
                cardRank = SIX;
                break;
            case 6:
                cardRank = SEVEN;
                break;
            case 7:
                cardRank = EIGHT;
                break;
            case 8:
                cardRank = NINE;
                break;
            case 9:
                cardRank = TEN;
                break;
            case 10:
                cardRank = JACK;
                break;
            case 11:
                cardRank = QUEEN;
                break;
            case 12:
                cardRank = KING;
                break;
            }
            Card newCard = generateCard(cardSuit, cardRank);
            deck.push_back(newCard);
        }
    }
}

void Deck::printDeck()
{
    for (int card = 0; card < deck.size(); card++)
    {
        cout << card << '\t';
        printCard(deck[card]);
    }
}

bool sortBySuit(Card &card1, Card &card2)
{
    return (card1.suit < card2.suit);
};