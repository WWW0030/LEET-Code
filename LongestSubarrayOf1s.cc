#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool allZero = true;
        bool allOne = true;
        bool prevZero = false;
        int currentLongest = 0;
        int prevStringOfOne = 0;
        int max = 0;
        if (nums.size() == 1) return 0;
        for (int i : nums) {
            if (i == 0) {
                allOne = false;
                // More than two zeros side by side
                if (prevZero == true) {
                    if (currentLongest + prevStringOfOne > max) {
                        max = currentLongest + prevStringOfOne;
                    }
                    prevZero = true;
                    currentLongest = 0;
                    prevStringOfOne = 0;
                }
                else {
                    if (currentLongest + prevStringOfOne > max) {
                        max = currentLongest + prevStringOfOne;
                    }
                    prevStringOfOne = currentLongest;
                    currentLongest = 0;
                    prevZero = true;
                }
            }
            if (i == 1) {
                allZero = false;
                currentLongest++;
                prevZero = false;
            }
        }
        if (currentLongest + prevStringOfOne > max) {
            max = currentLongest + prevStringOfOne;
        }
        if (allZero) return 0;
        if (allOne) return max - 1;
        return max;

    }
};