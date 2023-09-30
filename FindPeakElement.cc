#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (nums[mid] < nums[mid+1] && nums[mid] > nums[mid-1]) return mid;
            else if (nums[mid] < nums[mid+1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};