#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> Ypen (customers.length() + 1);
        vector<int> Npen (customers.length() + 1);
        int curYpen = 0;
        int curNpen = 0;
        //Calculate Ypen
        Ypen[customers.length()] = 0;
        for(int i = customers.length()-1; i >= 0; --i) {
            if (customers[i] == 'Y') {
                curYpen++;
            }
            Ypen[i] = curYpen;
        }
        if (customers[0] == 'Y') {
            Ypen[0] = curYpen + 1;
        } 
        //Calculate Npen
        Npen[0] = 0;
        for (int i = 1; i <= customers.length(); ++i) {
            if (customers[i - 1] == 'N') {
                curNpen++;
            }
            Npen[i] = curNpen;
        }
        int min = Ypen[0] + Npen[0];
        int idx = 0;
        for (int i = 0; i < Ypen.size(); ++i) {
            if (Ypen[i] + Npen[i] < min) {
                idx = i;
                min = Ypen[i] + Npen[i];
            }
        }
        return idx;
    }
};