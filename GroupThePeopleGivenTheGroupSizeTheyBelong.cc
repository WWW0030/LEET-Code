#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> curQueue;
        vector<vector<int>> returnVal;
        for (int i = 0; i < groupSizes.size(); ++i) {
            if (groupSizes[i] == 1) {
                vector<int> tempVec;
                tempVec.push_back(i);
                returnVal.push_back(tempVec);
            }
            else {
                auto key = curQueue.find(groupSizes[i]);
                if (key != curQueue.end()) {
                    key->second.push_back(i);
                    if (key->second.size() == key->first) {
                        returnVal.push_back(key->second);
                        curQueue.erase(key);
                    }
                }
                else {
                    vector<int> tempVec;
                    tempVec.push_back(i);
                    curQueue.insert(make_pair(groupSizes[i], tempVec));
                }
            }
        }
        return returnVal;
    }
};