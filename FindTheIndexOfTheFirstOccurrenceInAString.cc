#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // Hash search with 29?
    int strStr(string haystack, string needle) {
        int hashKey = 101;
        if (needle.length() > haystack.length()) return -1;
        // Calculate hashvalue for needle
        int needleHashValue = 0;
        for (char c : needle) {
            needleHashValue += c;
            needleHashValue = needleHashValue % hashKey;
        }
        cout << "NeedleHashValue " << needleHashValue << endl;
        // Calculate hashvalue for starting value
        int curHaystackHashValue = 0;
        for (int i = 0; i < needle.length(); ++i) {
            curHaystackHashValue += haystack[i];
            curHaystackHashValue = curHaystackHashValue % hashKey;
        }
        if (curHaystackHashValue == needleHashValue && haystack.substr(0, needle.length()) == needle) return 0;
        // Keep rolling
        for (int i = needle.length(); i < haystack.length() + 1; ++i) {
            curHaystackHashValue -= haystack[i - needle.length()];
            curHaystackHashValue += haystack[i] + hashKey;
            curHaystackHashValue = curHaystackHashValue % hashKey;
            cout << "Hashvalue " << curHaystackHashValue << endl;
            cout << "comparing " << haystack.substr(i - needle.length() + 1, needle.length()) << "!" << endl;
            if (curHaystackHashValue == needleHashValue && haystack.substr(i - needle.length() + 1, needle.length()) == needle) {
                return i - needle.length() + 1;
            }
        }
        return -1;
    }
};