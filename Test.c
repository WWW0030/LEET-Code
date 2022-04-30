#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    if(-INFINITY < -2147483648) printf("HEYHEY");
    if(INFINITY > 2147483647) printf("OHOH");
}