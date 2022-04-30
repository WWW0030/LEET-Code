#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int numTreesHelper(int n, int *stored) {
    if (stored[n] != -1) return stored[n];
    int ans = 0;
    for(int i = 0; i < n; ++i) ans = ans + numTreesHelper(i, stored) * numTreesHelper(n - 1 - i, stored);
    stored[n] = ans;
    return ans;
}

int numTrees(int n) {
    int *stored = malloc(sizeof(int) * 20);
    for(int i = 0; i < 20; ++i) stored[i] = -1;
    stored[1] = 1;
    stored[0] = 1;
    return numTreesHelper(n, stored);
}

int main() {
    for (int i = 1; i <= 19; ++i) {
        printf("Current %d is %d\n", i, numTrees(i));
    }
}