#include "bits/stdc++.h"
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>&nums2) {
    int med = nums1.size() + nums2.size();
    int c1 = 0, c2 = 0, prev;
    bool even = false;
    if (med % 2 == 0) even = true;
    med = med / 2;
    
    //edge case:
    if (nums1.size() == 0 && !even) return nums2[med];
    else if (nums1.size() == 0 && even) return ((double)nums2[med] + (double)nums2[med-1]) / 2;
    else if (nums2.size() == 0 && !even) return nums1[med];
    else if (nums2.size() == 0 && even) return ((double)nums1[med] + (double)nums1[med-1]) / 2;      


    while(med != 0) {
        if (c1 == nums1.size()) {
            prev = nums2[c2];
            ++c2;
        }
        else if (c2 == nums2.size()) {
            prev = nums1[c1];
            ++c1;
        }
        else if (nums1[c1] >= nums2[c2]) {
            prev = nums2[c2];
            ++c2;
        }
        else {
            prev = nums1[c1];
            ++c1;
        }
        --med;
    }

    if (!even && c2 == nums2.size()) return nums1[c1];
    else if (!even && c1 == nums1.size()) return nums2[c2];
    else if (!even) return min(nums1[c1], nums2[c2]);
    else if (c2 == nums2.size()) return ((double) prev + (double) nums1[c1]) / 2;
    else if (c1 == nums1.size()) return ((double) prev + (double) nums2[c2]) / 2;
    else return ((double) prev + (double) min(nums1[c1], nums2[c2])) / 2;
}

int main() {
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    cout << findMedianSortedArrays(a, b);
}
