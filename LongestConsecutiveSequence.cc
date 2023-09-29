#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {\
        if (nums.size() == 0) return 0;
        unordered_map<int, int> temp;
        int maxLength = 1;
        for (int i : nums) {
            auto key = temp.find(i);
            if (key == temp.end()) {
                auto leftK = temp.find(i-1);
                auto rightK = temp.find(i+1);
                if (leftK == temp.end() && rightK == temp.end()) {
                    // no adjacent consec
                    cout << "Case 1" << endl;
                    temp.emplace(make_pair(i, i));
                }
                else if (leftK == temp.end()) {
                    // right end exists
                    cout << "Case 2" << endl;
                    int tempVal = rightK->second;
                    temp.emplace(make_pair(i, rightK->second));
                    auto rightBound = temp.find(rightK->second);
                    rightBound->second = i;
                    int curLength = abs(tempVal - i) + 1;
                    if (curLength > maxLength) {
                        maxLength = curLength;
                    }

                }
                else if (rightK == temp.end()) {
                    // left end exists
                    cout << "Case 3" << endl;
                    int tempVal = leftK->second;
                    temp.emplace(make_pair(i, leftK->second));
                    auto leftBound = temp.find(leftK->second);
                    leftBound->second = i;
                    int curLength = abs(tempVal - i) + 1;
                    if (curLength > maxLength) {
                        maxLength = curLength;
                    }
                }
                else {
                    // left and right end exists
                    cout << "Case 4" << endl;
                    temp.emplace(make_pair(i, i));
                    auto leftBound = temp.find(leftK->second);
                    auto rightBound = temp.find(rightK->second);
                    int tempVal = leftK->second;
                    leftBound->second = rightK->second;
                    rightBound->second = tempVal;
                    int curLength = abs(leftBound->second - rightBound->second) + 1;
                    if (curLength > maxLength) {
                        maxLength = curLength;
                    }
                }
            }
        }
        return maxLength;
    }
};