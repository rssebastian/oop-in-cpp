#include <iostream>
#include "Deck.h"

using namespace std;

int main()
{
    Deck deck;
    deck.printDeck();
    cout << "-------Cutting the deck @Index: 26-------\n";
    deck.cut(26);
    deck.printDeck();
    cout << "------------Sorting the deck--------------\n";
    deck.sort();
    deck.printDeck();
    cout << "-------------Drawing a card---------------\n";
    deck.draw();
    return 0;
}

// TEST CASE OUTPUT
// Deck generated and shuffled!
// 0       Suit: Spades, Rank: 9
// 1       Suit: Diamonds, Rank: 7
// 2       Suit: Diamonds, Rank: J
// 3       Suit: Hearts, Rank: 9
// 4       Suit: Spades, Rank: 5
// 5       Suit: Hearts, Rank: 2
// 6       Suit: Clubs, Rank: Q
// 7       Suit: Spades, Rank: 3
// 8       Suit: Diamonds, Rank: 10
// 9       Suit: Spades, Rank: 8
// 10      Suit: Clubs, Rank: K
// 11      Suit: Clubs, Rank: 3
// 12      Suit: Hearts, Rank: 6
// 13      Suit: Spades, Rank: Q
// 14      Suit: Clubs, Rank: 6
// 15      Suit: Diamonds, Rank: Q
// 16      Suit: Hearts, Rank: A
// 17      Suit: Diamonds, Rank: K
// 18      Suit: Hearts, Rank: 10
// 19      Suit: Spades, Rank: J
// 20      Suit: Diamonds, Rank: A
// 21      Suit: Diamonds, Rank: 8
// 22      Suit: Clubs, Rank: 2
// 23      Suit: Clubs, Rank: 7
// 24      Suit: Spades, Rank: 7
// 25      Suit: Clubs, Rank: 10
// 26      Suit: Spades, Rank: 10
// 27      Suit: Diamonds, Rank: 9
// 28      Suit: Diamonds, Rank: 4
// 29      Suit: Spades, Rank: K
// 30      Suit: Diamonds, Rank: 2
// 31      Suit: Hearts, Rank: 8
// 32      Suit: Diamonds, Rank: 5
// 33      Suit: Clubs, Rank: 5
// 34      Suit: Spades, Rank: 2
// 35      Suit: Spades, Rank: A
// 36      Suit: Hearts, Rank: Q
// 37      Suit: Hearts, Rank: K
// 38      Suit: Hearts, Rank: 5
// 39      Suit: Hearts, Rank: 3
// 40      Suit: Spades, Rank: 6
// 41      Suit: Clubs, Rank: 4
// 42      Suit: Diamonds, Rank: 6
// 43      Suit: Hearts, Rank: 4
// 44      Suit: Diamonds, Rank: 3
// 45      Suit: Hearts, Rank: 7
// 46      Suit: Hearts, Rank: J
// 47      Suit: Clubs, Rank: A
// 48      Suit: Spades, Rank: 4
// 49      Suit: Clubs, Rank: 9
// 50      Suit: Clubs, Rank: J
// 51      Suit: Clubs, Rank: 8
// -------Cutting the deck @Index: 26-------
// 0       Suit: Spades, Rank: 10
// 1       Suit: Diamonds, Rank: 9
// 2       Suit: Diamonds, Rank: 4
// 3       Suit: Spades, Rank: K
// 4       Suit: Diamonds, Rank: 2
// 5       Suit: Hearts, Rank: 8
// 6       Suit: Diamonds, Rank: 5
// 7       Suit: Clubs, Rank: 5
// 8       Suit: Spades, Rank: 2
// 9       Suit: Spades, Rank: A
// 10      Suit: Hearts, Rank: Q
// 11      Suit: Hearts, Rank: K
// 12      Suit: Hearts, Rank: 5
// 13      Suit: Hearts, Rank: 3
// 14      Suit: Spades, Rank: 6
// 15      Suit: Clubs, Rank: 4
// 16      Suit: Diamonds, Rank: 6
// 17      Suit: Hearts, Rank: 4
// 18      Suit: Diamonds, Rank: 3
// 19      Suit: Hearts, Rank: 7
// 20      Suit: Hearts, Rank: J
// 21      Suit: Clubs, Rank: A
// 22      Suit: Spades, Rank: 4
// 23      Suit: Clubs, Rank: 9
// 24      Suit: Clubs, Rank: J
// 25      Suit: Clubs, Rank: 8
// 26      Suit: Spades, Rank: 9
// 27      Suit: Diamonds, Rank: 7
// 28      Suit: Diamonds, Rank: J
// 29      Suit: Hearts, Rank: 9
// 30      Suit: Spades, Rank: 5
// 31      Suit: Hearts, Rank: 2
// 32      Suit: Clubs, Rank: Q
// 33      Suit: Spades, Rank: 3
// 34      Suit: Diamonds, Rank: 10
// 35      Suit: Spades, Rank: 8
// 36      Suit: Clubs, Rank: K
// 37      Suit: Clubs, Rank: 3
// 38      Suit: Hearts, Rank: 6
// 39      Suit: Spades, Rank: Q
// 40      Suit: Clubs, Rank: 6
// 41      Suit: Diamonds, Rank: Q
// 42      Suit: Hearts, Rank: A
// 43      Suit: Diamonds, Rank: K
// 44      Suit: Hearts, Rank: 10
// 45      Suit: Spades, Rank: J
// 46      Suit: Diamonds, Rank: A
// 47      Suit: Diamonds, Rank: 8
// 48      Suit: Clubs, Rank: 2
// 49      Suit: Clubs, Rank: 7
// 50      Suit: Spades, Rank: 7
// 51      Suit: Clubs, Rank: 10
// ------------Sorting the deck--------------
// Deck has been sorted!
// 0       Suit: Spades, Rank: A
// 1       Suit: Spades, Rank: 2
// 2       Suit: Spades, Rank: 3
// 3       Suit: Spades, Rank: 4
// 4       Suit: Spades, Rank: 5
// 5       Suit: Spades, Rank: 6
// 6       Suit: Spades, Rank: 7
// 7       Suit: Spades, Rank: 8
// 8       Suit: Spades, Rank: 9
// 9       Suit: Spades, Rank: 10
// 10      Suit: Spades, Rank: J
// 11      Suit: Spades, Rank: Q
// 12      Suit: Spades, Rank: K
// 13      Suit: Hearts, Rank: A
// 14      Suit: Hearts, Rank: 2
// 15      Suit: Hearts, Rank: 3
// 16      Suit: Hearts, Rank: 4
// 17      Suit: Hearts, Rank: 5
// 18      Suit: Hearts, Rank: 6
// 19      Suit: Hearts, Rank: 7
// 20      Suit: Hearts, Rank: 8
// 21      Suit: Hearts, Rank: 9
// 22      Suit: Hearts, Rank: 10
// 23      Suit: Hearts, Rank: J
// 24      Suit: Hearts, Rank: Q
// 25      Suit: Hearts, Rank: K
// 26      Suit: Diamonds, Rank: A
// 27      Suit: Diamonds, Rank: 2
// 28      Suit: Diamonds, Rank: 3
// 29      Suit: Diamonds, Rank: 4
// 30      Suit: Diamonds, Rank: 5
// 31      Suit: Diamonds, Rank: 6
// 32      Suit: Diamonds, Rank: 7
// 33      Suit: Diamonds, Rank: 8
// 34      Suit: Diamonds, Rank: 9
// 35      Suit: Diamonds, Rank: 10
// 36      Suit: Diamonds, Rank: J
// 37      Suit: Diamonds, Rank: Q
// 38      Suit: Diamonds, Rank: K
// 39      Suit: Clubs, Rank: A
// 40      Suit: Clubs, Rank: 2
// 41      Suit: Clubs, Rank: 3
// 42      Suit: Clubs, Rank: 4
// 43      Suit: Clubs, Rank: 5
// 44      Suit: Clubs, Rank: 6
// 45      Suit: Clubs, Rank: 7
// 46      Suit: Clubs, Rank: 8
// 47      Suit: Clubs, Rank: 9
// 48      Suit: Clubs, Rank: 10
// 49      Suit: Clubs, Rank: J
// 50      Suit: Clubs, Rank: Q
// 51      Suit: Clubs, Rank: K
// -------------Drawing a card---------------
// You drew a card! It was:
// Suit: Spades, Rank: A