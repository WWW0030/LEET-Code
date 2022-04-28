#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int fact(int n) {
    int ans = 1;
    while(n != 1) {
        ans = ans * n;
        --n;
    } 
    return ans;
}

char *getPermutation(int n, int k) {
    char *ans = malloc(sizeof(char) * (n + 1));
    ans[n] = '\0';
    int currentSize = n;
    char currentList[n];
    int currentCounter = 0;
    for(int i = 1; i < n + 1; ++i) currentList[i - 1] = i + '0';
    while(currentSize != 1) {
        int currentfact = fact(currentSize - 1);
        int index = (k - 1) / currentfact;
        ans[currentCounter] = currentList[index];
        --currentSize;
        for(int i = index; i < currentSize; ++i) currentList[i] = currentList[i + 1];
        ++currentCounter;
        k = k % currentfact;
        if (k == 0) {
            for(int i = currentSize - 1; i >= 0; --i) {
                ans[currentCounter] = currentList[i];
                ++ currentCounter;
            }
            return ans;
        }
    }
    ans[currentCounter] = currentList[0];
    return ans;
}