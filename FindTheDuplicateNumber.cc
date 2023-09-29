#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> found(100001, false);
        for (int i : nums) {
            if (found[i]) return i;
            else found[i] = true;
        }
        return 0;
    }
};