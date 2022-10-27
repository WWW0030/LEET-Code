#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int a=0; a<nums.size()-2; ++a) {
        while(a!=0 && a<nums.size()-2 && nums[a]==nums[a-1]) ++a;
        int l = a+1, r = nums.size()-1;
        while(l < r) {
            if(nums[a] + nums[l] + nums[r] > 0) --r;
            else if(nums[a] + nums[l] + nums[r] <0) ++l;
            else {
                vector<int> temp = {nums[a], nums[l], nums[r]};
                ans.emplace_back(temp);
                while(l < nums.size() && nums[l] == temp[1] && l < r) ++l;
                while(r > 0 && nums[r] == temp[2] && l < r) --r;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> temp = {0, 0 ,0, 0};
    cout << threeSum(temp)[0][1];
}