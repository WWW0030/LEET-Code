#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int reverse(int x){
    bool neg = false;
    if (x == 0) return 0;
    if (x == -2147483648) return 0;
    if (x < 0) {
        neg = true;
        x = x * (-1);
    }
    if(x > 1000000000) {
        int test = x;
        if (test % 10 > 2) {
            return 0;
        }
        else if (test % 10 == 2) {
            test = test/10;
            if (test % 10 > 1) {
                return 0;
            }
            else if (test % 10 == 1) {
                test = test/10;
                if (test % 10 > 4) {
                    return 0;
                }
                else if (test % 10 == 4) {
                    test = test/10;
                    if (test % 10 > 7) {
                        return 0;
                    }
                    else if (test % 10 == 7) {
                        test = test/10;
                        if (test % 10 > 4) {
                            return 0;
                        }
                        else if (test % 10 == 4) {
                            test = test/10;
                            if (test % 10 > 8) {
                                return 0;
                            }
                            else if (test % 10 == 8) {
                                test = test/10;
                                if (test % 10 > 3) {
                                    return 0;
                                }
                                else if (test % 10 == 3) {
                                    test = test/10;
                                    if (test % 10 > 6) {
                                        return 0;
                                    }
                                    else if (test % 10 == 6) {
                                        test = test/10;
                                        if (test % 10 > 4) {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    while (x >= 10) {
        ans = ans * 10 + (x % 10);
        x = x/10;
    }
    ans = ans * 10 + x;
    if (neg) {
        ans = ans * -1;
    }
    return ans;
}