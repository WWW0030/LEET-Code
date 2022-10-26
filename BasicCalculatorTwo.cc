#include "bits/stdc++.h"

using namespace std;

int calculateh(istringstream& s);

int calculate(string str) {
    istringstream s(str);
    return calculateh(s);
}

int calculateh(istringstream& s) {
    int result = 0;
    bool adding = true;
    char c;
    while(s) {
        c = s.peek();
        if (!s) break;
        switch(c) {
            case '+':
                c = s.get();
                adding = true;
                break;
            case '-':
                c = s.get();
                adding = false;
                break;
            case '(':
                c = s.get();
                if (adding) result += calculateh(s);
                else result -= calculateh(s);
                break;
            case ')':
                c = s.get();
                return result;
            case ' ': 
                c = s.get();
                break;
            default:
                int n = 0;
                s >> n;
                if (adding) result += n;
                else result -= n;
                char c;
                c = s.get();
                if (s) s.unget();
                break;
        }
    }
    return result;
}

int main() {
    cout << calculate("2-1 + 2 ");
}