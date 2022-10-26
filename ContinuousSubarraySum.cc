#include "bits/stdc++.h"
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2) return false;
    unordered_map<int, int> prefix;
    nums[0] = nums[0] % k;
    int prev = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        nums[i] = (nums[i] + nums[i-1]) % k;
        if (nums[i] == 0) return true;
        if (prefix.find(nums[i]) != prefix.end()) return true;
        prefix.try_emplace(prev);
        prev = nums[i];
    }
    return false;
}