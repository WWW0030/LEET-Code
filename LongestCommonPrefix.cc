#include "bits/stdc++.h"
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int counter=0;
    string prefix="";
    bool done = false;
    char cur;
    while(!done) {
        if (counter >= strs[0].length()) {
            done = true;
            break;
        }
        else cur = strs[0][counter];
        for(string s : strs) {
            if (counter >= s.length()) {
                done = true;
                break;
            }
            else if (s[counter] != cur) {
                done = true;
                break;
            }
        }
        if (!done) {
            prefix += cur;
            ++counter;            
        }
    }
    return prefix;
}