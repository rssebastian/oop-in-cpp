#include "Quicksort.h"
#include "Card.h"
#include <vector>

void quickSort(vector<Card> &v)
{
    quickSort(v, 0, v.size() - 1);
}

void quickSort(vector<Card> &v, int lo, int hi)
{
    if (hi <= lo)
        return;
    int j = partition(v, lo, hi);
    quickSort(v, lo, j - 1);
    quickSort(v, j + 1, hi);
}

int partition(vector<Card> &v, int lo, int hi)
{
    int i = lo, j = hi + 1;
    while (true)
    {
        while (isLess(v[++i], v[lo]))
        {
            if (i == hi)
                break;
        }
        while (isLess(v[lo], v[--j]))
        {
            if (j == lo)
                break;
        }
        if (i >= j)
            break;
        exch(v, i, j);
    }
    exch(v, lo, j);
    return j;
}

bool isLess(Card &card1, Card &card2)
{
    if (card1.suit == card2.suit)
    {
        return card1.rank < card2.rank;
    }
    else
    {
        return card1.suit < card2.suit;
    }
}

void exch(vector<Card> &v, int el1, int el2)
{
    Card temp = v[el1];
    v[el1] = v[el2];
    v[el2] = temp;
}
