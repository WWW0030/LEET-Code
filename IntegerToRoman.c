#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int repeat(char *ans, int repeat, int index, char c) {
    while (repeat != 0) {
        ans[index] = c;
        --repeat;
        ++index;
    }
    return index;
}

char * intToRoman(int num){
    char *ans = malloc(16 * sizeof(char));
    int index = 0;
    index = repeat(ans, num/1000, index, 'M');
    num = num % 1000;
    if (num / 100 == 9) {
        ans[index] = 'C';
        ++index;
        ans[index] = 'M';
        ++index;
        num = num - 900;
    }
    else if (num / 100 == 4) {
        ans[index] = 'C';
        ++index;
        ans[index] = 'D';
        ++index;
        num = num - 400;
    }
    else if (num / 100 >= 5) {
        ans[index] = 'D';
        ++index;
        num = num - 500;
    }
    index = repeat(ans, num/100, index, 'C');
    num = num % 100;
    if (num / 10 == 9) {
        ans[index] = 'X';
        ++index;
        ans[index] = 'C';
        ++index;
        num = num - 90;
    }
    else if (num / 10 == 4) {
        ans[index] = 'X';
        ++index;
        ans[index] = 'L';
        ++index;
        num = num - 40;
    }
    else if (num / 10 >= 5) {
        ans[index] = 'L';
        ++index;
        num = num - 50;
    }
    index = repeat(ans, num/10, index, 'X');
    num = num % 10;
    if (num == 9) {
        ans[index] = 'I';
        ++index;
        ans[index] = 'X';
        ++index;
        num = num - 9;
    }
    else if (num == 4) {
        ans[index] = 'I';
        ++index;
        ans[index] = 'V';
        ++index;
        num = num - 4;
    }
    else if (num >= 5) {
        ans[index] = 'V';
        ++index;
        num = num - 5;
    }
    index = repeat(ans, num, index, 'I');
    ans[index] = NULL;
    return ans;
}

int main() {
    int i = 3888;
    printf("%s", intToRoman(i));
}