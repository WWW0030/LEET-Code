#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int romanToInt(char * s) {
    int past = 0;
    int sum = 0;
    for (int i = 0; i < 16; i++) {
        if (s[i] == 'M') {
            if (past == 100) {
                sum = sum + 1000 - 200;
                past = 1000;
            }
            else {
                sum = sum + 1000;
                past = 1000;
            }
        }
        else if (s[i] == 'D') {
            if (past == 100) {
                sum = sum + 500 - 200;
                past = 500;
            }
            else {
                sum = sum + 500;
                past = 500;
            }
        }
        else if (s[i] == 'C') {
            if (past == 10) {
                sum = sum + 100 - 20;
                past = 100;
            }
            else {
                sum = sum + 100;
                past = 100;
            }
        }
        else if (s[i] == 'L') {
            if (past == 10) {
                sum = sum + 50 - 20;
                past = 50;
            }
            else {
                sum = sum + 50;
                past = 50;
            }
        }
        else if (s[i] == 'X') {
            if (past == 1) {
                sum = sum + 10 - 2;
                past = 10;
            }
            else {
                sum = sum + 10;
                past = 10;
            }
        }
        else if (s[i] == 'V') {
            if (past == 1) {
                sum = sum + 5 - 2;
                past = 5;
            }
            else {
                sum = sum + 5;
                past = 5;
            }
        }
        else if (s[i] == 'I') {
            ++sum;
            past = 1;
        }
        else {
            return sum;
        }        
    }
    return sum;
}

int main() {
    char s[] = "MCMXCIV";
    printf("%d", romanToInt(s));
}