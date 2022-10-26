#include "bits/stdc++.h"

using namespace std;

bool isValid(string str) {
    if (str.length() % 2 == 1) return false;
    istringstream s(str);
    stack<char> stack;
    do {
        char c = s.get();
        switch (c) {
            case '(':
                stack.push(c);
                break;
            case '[':
                stack.push(c);
                break;
            case '{':
                stack.push(c);
                break;
            case ')':
                if (stack.empty() or stack.top()!='(') return false;
                stack.pop();
                break;
            case ']':
                if (stack.empty() or stack.top()!='[') return false;
                stack.pop();
                break;
            case '}':
                if (stack.empty() or stack.top()!='{') return false;
                stack.pop();
                break;
        }
    } while(s);
    return stack.empty();
}