    #include "bits/stdc++.h"
using namespace std;

    
    vector<string> letterCombinations(string digits) {
        cout << "heck -1" << endl;
        vector<vector<string>> phoneBox(8);
        phoneBox[0] = {"a", "b", "c"};
        phoneBox[1] = {"d", "e", "f"};
        phoneBox[2] = {"g", "h", "i"};
        phoneBox[3] = {"j", "k", "l"};
        phoneBox[4] = {"m", "n", "o"};
        phoneBox[5] = {"p", "q", "r", "s"};
        phoneBox[6] = {"t", "u", "v"};
        phoneBox[7] = {"w", "x", "y", "z"};
        vector<string> ans; 
        cout << "HEck0" << endl;
        int num = digits[0] - 48 - 2;
        cout << "Heck1" << endl;
        ans = phoneBox[num];
        for (char i : digits.substr(1)) {
            num = i - 48 - 2;
            int orilen = ans.size();
            vector<string> anstemp = ans;
            for (int i = 0; i < phoneBox[num].size() - 1; ++i) {
                ans.insert(ans.end(), anstemp.begin(), anstemp.end());
            }
            for (int i = 0; i < phoneBox[num].size(); ++i) {
                for (int m = 0; m < orilen; ++m) {
                    ans[i*orilen + m] += phoneBox[num][i];
                }
            }
        }
        return ans;
    }

    int main() {
        string temp = "23";
        cout << "nope" << endl;
        for (auto s : letterCombinations(temp)) {
            cout << s << endl;
        }
        return 0;
    }