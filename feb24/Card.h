#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int NUMSUITS = 4;
const int NUMRANKS = 13;
enum Suit
{
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS
};
enum Rank
{
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

struct Card
{
    enum Suit suit;
    enum Rank rank;
};

Card generateCard(enum Suit suit, enum Rank rank);
Card generateRandomCard();
void printCard(Card card);

#endif