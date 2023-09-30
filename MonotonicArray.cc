#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase;
        bool eq = true;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (prev < nums[i] && eq) {
                increase = true;
                eq = false;
            }
            else if (prev > nums[i] && eq) {
                increase = false;
                eq = false;
            }
            else if (prev == nums[i] && eq) {
                eq = true;
            }
            else if (prev < nums[i] && !eq && !increase) {
                return false;
            }
            else if (prev > nums[i] && !eq && increase) {
                return false;
            }
            prev = nums[i];
        }

        return true;
    }
};