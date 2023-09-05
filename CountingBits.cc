#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> returnValue (n+1);
        returnValue[0] = 0;
        for (int i = 1; i < n+1; ++i) {
            if (i % 2 == 0) {
                returnValue[i] = returnValue[i/2];
            }
            else {
                returnValue[i] = returnValue[i/2] + 1;
            }
        }
        return returnValue;
    }
};