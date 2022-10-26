#include "bits/stdc++.h"

using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string ans = "";
    int cycle = numRows*2 - 2;
    for(int i=0; i<numRows; ++i) {
        for(int a=0; a<s.length(); a+=cycle) {
            if(i==0) ans+=s[a];
            else if(i==numRows-1 && a+i < s.length()) ans+=s[a+i];
            else {
                if (a+i < s.length()) ans+=s[a+i];
                if (a+cycle-i < s.length()) ans+=s[a+cycle-i];
            }
        }
    }
    return ans;
}