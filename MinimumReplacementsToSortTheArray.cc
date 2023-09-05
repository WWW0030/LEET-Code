#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int prev = nums[nums.size() - 1];
        long counter = 0;
        for (int i = nums.size() - 2; i >=0; --i) {
            if (nums[i] > prev) {
                int split = nums[i] / prev;
                if (nums[i] % prev != 0) split++;
                prev = nums[i] / split;
                counter = counter + split - 1;
            }
            else {
                prev = nums[i];
            }
        }
        return counter;
    }
};