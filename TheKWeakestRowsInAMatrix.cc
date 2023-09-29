#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //Make an array of pairs
        vector<pair<int, int>> sortingArray;
        for (int i = 0; i < mat.size(); ++i) {
            int low = 0;
            int high = mat[i].size() - 1;
            while (low < high) {
                int mid = (low + high) / 2;
                if (mat[i][mid] == 1) {
                    //Move up
                    low = mid + 1;
                }
                else {
                    //Move down
                    high = mid - 1;
                }
            }
            cout << i << low << endl;
            if (mat[i][low] == 0) sortingArray.push_back(make_pair(low - 1, i));
            else sortingArray.push_back(make_pair(low, i));
        }
        sort(sortingArray.begin(), sortingArray.end());
        vector<int> returnVal;
        for (int i = 0; i < k; ++i) {
            returnVal.push_back(sortingArray[i].second);
        }
        return returnVal;
    }
};