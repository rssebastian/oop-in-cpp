#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};
enum Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ACE,
    JACK,
    QUEEN,
    KING
};

struct Card
{
    enum Suit suit;
    enum Rank rank;
};

Card generateCard();
void printCard(Card card);

int main()
{
    srand(time(0));

    Card hand[5];
    cout << "Your Hand: " << endl;
    for (int card = 0; card < 5; card++)
    {
        hand[card] = generateCard();
        cout << "Card #" << card + 1 << ": ";
        printCard(hand[card]);
    }
    return 0;
}

Card generateCard()
{
    Card newCard;
    Suit newCardSuit;
    Rank newCardRank;

    switch (rand() % 4)
    {
    case 0:
        newCard.suit = CLUBS;
        break;
    case 1:
        newCard.suit = DIAMONDS;
        break;
    case 2:
        newCard.suit = HEARTS;
        break;
    case 3:
        newCard.suit = SPADES;
        break;
    }

    switch (rand() % 13)
    {
    case 0:
        newCard.rank = TWO;
        break;
    case 1:
        newCard.rank = THREE;
        break;
    case 2:
        newCard.rank = FOUR;
        break;
    case 3:
        newCard.rank = FIVE;
        break;
    case 4:
        newCard.rank = SIX;
        break;
    case 5:
        newCard.rank = SEVEN;
        break;
    case 6:
        newCard.rank = EIGHT;
        break;
    case 7:
        newCard.rank = NINE;
        break;
    case 8:
        newCard.rank = TEN;
        break;
    case 9:
        newCard.rank = ACE;
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
    case ACE:
        cout << "Rank: A" << endl;
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

// TEST CASE OUTPUT
// ====================
// Your Hand:
// Card #1: Suit: Diamonds, Rank: 2
// Card #2: Suit: Clubs, Rank: J
// Card #3: Suit: Diamonds, Rank: A
// Card #4: Suit: Hearts, Rank: J
// Card #5: Suit: Diamonds, Rank: 9
// ====================
// Your Hand:
// Card #1: Suit: Diamonds, Rank: 3
// Card #2: Suit: Hearts, Rank: 8
// Card #3: Suit: Spades, Rank: J
// Card #4: Suit: Spades, Rank: 2
// Card #5: Suit: Hearts, Rank: 5
// ====================
// Card #1: Suit: Spades, Rank: K
// Card #2: Suit: Spades, Rank: 10
// Card #3: Suit: Clubs, Rank: 10
// Card #4: Suit: Clubs, Rank: 10
// Card #5: Suit: Diamonds, Rank: 8
// ====================