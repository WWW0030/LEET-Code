#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) even.emplace_back(nums[i]);
            else odd.emplace_back(nums[i]);
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};