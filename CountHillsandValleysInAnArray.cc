#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int begin = nums[0];
        int end = nums[nums.size() - 1];
        int curnumSeq = 0;
        int curMode = 0;
        int curHill = 0;
        int curVal = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1] && curMode == 1) {
                curHill ++;
                curMode = -1;
            }
            else if (nums[i] < nums[i-1] && curMode == 0) {
                curMode = -1;
                curnumSeq = 0;
            }
            else if (nums[i] < nums[i-1] && curMode == -1) {
                curnumSeq = 0;
            }
            else if (nums[i] == nums[i-1]) {
                curnumSeq++;
            }
            else if (nums[i] > nums[i-1] && curMode == 1) {
                curnumSeq = 0;
            }
            else if (nums[i] > nums[i-1] && curMode == 0) {
                curMode = 1;
            }
            else if (nums[i] > nums[i-1] && curMode == -1) {
                curVal ++;
                curMode = 1;
            }
        }
        return curHill + curVal;
    }
};