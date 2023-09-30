#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> returnVal;
        int curBegin = intervals[0][0];
        int curEnd = intervals[0][1];
        for (auto i : intervals) {
            if (i[0] > curEnd) {
                //Push this interval back, make new interval
                vector<int> temp;
                temp.push_back(curBegin);
                temp.push_back(curEnd);
                returnVal.push_back(temp);
                curBegin = i[0];
                curEnd = i[1];
            }
            else {
                curEnd = max(curEnd, i[1]);
            }
        }
        vector<int> temp;
        temp.push_back(curBegin);
        temp.push_back(curEnd);
        returnVal.push_back(temp);
        return returnVal;
    }
};