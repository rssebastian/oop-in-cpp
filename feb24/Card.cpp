#include "Card.h"

Card generateCard(enum Suit suit, enum Rank rank)
{
    Card newCard;
    newCard.suit = suit;
    newCard.rank = rank;
    return newCard;
}

Card generateRandomCard()
{
    Card newCard;
    Suit newCardSuit;
    Rank newCardRank;

    switch (rand() % NUMSUITS)
    {
    case 0:
        newCard.suit = SPADES;
        break;
    case 1:
        newCard.suit = HEARTS;
        break;
    case 2:
        newCard.suit = DIAMONDS;
        break;
    case 3:
        newCard.suit = CLUBS;
        break;
    }

    switch (rand() % NUMRANKS)
    {
    case 0:
        newCard.rank = ACE;
        break;
    case 1:
        newCard.rank = TWO;
        break;
    case 2:
        newCard.rank = THREE;
        break;
    case 3:
        newCard.rank = FOUR;
        break;
    case 4:
        newCard.rank = FIVE;
        break;
    case 5:
        newCard.rank = SIX;
        break;
    case 6:
        newCard.rank = SEVEN;
        break;
    case 7:
        newCard.rank = EIGHT;
        break;
    case 8:
        newCard.rank = NINE;
        break;
    case 9:
        newCard.rank = TEN;
        break;
    case 10:
        newCard.rank = JACK;
        break;
    case 11:
        newCard.rank = QUEEN;
        break;
    case 12:
        newCard.rank = KING;
        break;
    }
    return newCard;
}

void printCard(Card card)
{
    switch (card.suit)
    {
    case CLUBS:
        cout << "Suit: Clubs, ";
        break;
    case DIAMONDS:
        cout << "Suit: Diamonds, ";
        break;
    case HEARTS:
        cout << "Suit: Hearts, ";
        break;
    case SPADES:
        cout << "Suit: Spades, ";
        break;
    }

    switch (card.rank)
    {
    case ACE:
        cout << "Rank: A" << endl;
        break;
    case TWO:
        cout << "Rank: 2" << endl;
        break;
    case THREE:
        cout << "Rank: 3" << endl;
        break;
    case FOUR:
        cout << "Rank: 4" << endl;
        break;
    case FIVE:
        cout << "Rank: 5" << endl;
        break;
    case SIX:
        cout << "Rank: 6" << endl;
        break;
    case SEVEN:
        cout << "Rank: 7" << endl;
        break;
    case EIGHT:
        cout << "Rank: 8" << endl;
        break;
    case NINE:
        cout << "Rank: 9" << endl;
        break;
    case TEN:
        cout << "Rank: 10" << endl;
        break;
    case JACK:
        cout << "Rank: J" << endl;
        break;
    case QUEEN:
        cout << "Rank: Q" << endl;
        break;
    case KING:
        cout << "Rank: K" << endl;
        break;
    }
}