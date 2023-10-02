#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        string returnWord;
        ss << s;
        while(ss) {
            string word;
            ss >> word;
            returnWord += reverseWord(word) + " ";
        }
        return returnWord.substr(0, returnWord.length() - 2);
    }
    string reverseWord(string s) {
        string word;
        for (int i = s.length() - 1; i >= 0; --i) {
            word = word + s[i];
        }
        return word;
    }
};