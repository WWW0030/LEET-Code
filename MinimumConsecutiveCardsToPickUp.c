
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int minimumCardPickup(int *cards, int cardsSize) {
    if(cardsSize == 1) return -1;
    int min = 100001;
    for(int i = 0; i < cardsSize - 1; ++i) {
        bool notFound = true;
        int m = i + 1;
        while(notFound && m != cardsSize) {
            if(cards[i] == cards[m]) {
                min = fmin(min, m - i + 1);
                notFound = false;
            }
            ++m;
        }
    }
    if (min == 100001) return -1;
    return min;
}