// Quicksort code adapted to fit project from CIS27
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Card.h"
#include <vector>

bool isLess(Card &card1, Card &card2);
void exch(vector<Card> &v, int el1, int el2);
int partition(vector<Card> &v, int lo, int hi);
void quickSort(vector<Card> &v);
void quickSort(vector<Card> &v, int lo, int hi);

#endif