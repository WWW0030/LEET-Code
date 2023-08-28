#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        // Preprocess
        bool carry = false;
        string ans = "";
        if (a.length() < b.length()) {
            string c = a;
            a = b;
            b = c;
        }
        for (int i = 0; i < a.length(); ++i) {
            if (i >= b.length()) {
                if (a[a.length() - i - 1] == '0') {
                    if (carry) {
                        ans = "1" + ans;
                        carry = false;
                    }
                    else {
                        ans = "0" + ans;
                        carry = false;
                    }
                }
                else {
                    if (carry) {
                        ans = "0" + ans;
                        carry = true;
                    }
                    else {
                        ans = "1" + ans;
                        carry = false;
                    }
                }
            }
            else {
                if (a[a.length() - i - 1] == '0') {
                    if (b[b.length() - i - 1] == '0') {
                        if (carry) {
                            ans = "1" + ans; 
                            carry  = false;                           
                        }
                        else {
                            ans = "0" + ans;
                            carry = false;
                        }
                    }
                    else {
                        if (carry) {
                            ans = "0" + ans;
                            carry = true;
                        }
                        else {
                            ans = "1" + ans;
                            carry = false;
                        }
                    }
                }
                else {
                    if (b[b.length() - i - 1] == '0') {
                        if (carry) {
                            ans = "0" + ans;
                            carry = true;
                        }
                        else {
                            ans = "1" + ans;
                            carry = false;
                        }
                    }
                    else {
                        if (carry) {
                            ans = "1" + ans;
                            carry = true;
                        }
                        else {
                            ans = "0" + ans;
                            carry = true;
                        }
                    }
                }

            }
        }
        if (carry) ans = "1" + ans;
        return ans;
    }
};