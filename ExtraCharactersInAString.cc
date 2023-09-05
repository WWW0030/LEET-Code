#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> min (s.length() + 1);
        for (int i = 0; i <= s.length(); ++i) {
            min[i] = i;
        }
        for (int i = 0; i <= s.length(); ++i) {
            for (string word : dictionary) {
                if (i >= word.length() && s.substr(i - word.length(), word.length()) == word) {
                    int tempmin = min[i - word.length()];
                    if (tempmin < min[i]) {
                        min[i] = tempmin;
                    }
                }
            }
            if (i != 0 && min[i] > min[i-1] + 1) {
                min[i] = min[i-1] + 1;
            }
            cout << min[i];
        }
        return min[s.length()];
    }
};