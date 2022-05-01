
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *removeDigit(char *number, char digit) {
    int len = strlen(number);
    bool maxFilled = false;
    char *max = malloc(sizeof(char) * (len + 3));
    for(int i = 0; i < len; ++i) {
        if(number[i] == digit) {
            char *cur = malloc(sizeof(char) * (len + 3));
            for(int m = 0; m < i; m++) cur[m] = number[m];
            for(int m = i + 1; m < len + 1; m++) cur[m - 1] = number[m];
            cur[len - 1] = '\0';
            if(!maxFilled) {
                maxFilled = true;
                strcpy(max, cur);
            }
            else if(strcmp(max, cur) < 0) strcpy(max, cur);
        }
    }
    return max;
}

int main() {
    char ans[4] = {'3', '2', '1', '\0'};
    printf("%s", removeDigit(ans, '3'));
}