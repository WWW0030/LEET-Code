#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> generated(int numRows) {
        vector<vector<int>> returnVector;
        vector<int> firstRow;
        firstRow.push_back(1);
        returnVector.push_back(firstRow);
        for (int i = 1; i < numRows; ++i) {
            vector<int> tempVector;
            tempVector.push_back(1);
            int last = returnVector[i-1][0];
            for (int j = 1; j < returnVector[i-1].size(); ++j) {
                tempVector.push_back(last + returnVector[i-1][j]);
                last = returnVector[i-1][j];
            }
            tempVector.push_back(1);
            returnVector.push_back(tempVector);
        }
        return returnVector;
    }
};