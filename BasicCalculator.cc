#include "bits/stdc++.h"
using namespace std;

int pos = 0;

int calculateGetInt(string s) {
    string result = "";
    while(pos != s.length() && '0' <= s[pos] && s[pos] <= '9') {
        result = result + s[pos];
        ++pos;
    }
    cout << result;
    return stoi(result);
}

int calculate(string s) {
    int result = 0;
    bool adding = true;
    while(pos < s.length()) {
        char c = s[pos];
        switch(c) {
            case '+':
                ++pos;
                adding = true;
            case '-':
                ++ pos;
                adding = false;
            case '(':
                ++pos;
                if (adding) result += calculate(s);
                else result -= calculate(s);
            case ')':
                ++pos;
                return result;
            case ' ': ++pos;
            default:
                if (adding) result += calculateGetInt(s);
                else result -= calculateGetInt(s);
        }
    }
    return result;
}

int main() {
    string s = "123 + 312";
    cout << calculate(s);
}