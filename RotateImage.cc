#include "bits/stdc++.h"
using namespace std;
typedef vector< vector<int> > Matrix;
typedef vector<int> Row;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        Matrix middle;
        for(int i = 0; i < size; ++i)
        {
            Row row(size);
            for(int j = 0; j < size; ++j)
            {
                row[j] = 0;
            }
            middle.push_back(row);
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                middle[j][i] = matrix[i][j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = middle[i][size - 1 - j];
            }
        }
    }
};