#include<iostream>
#include<vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        vector<int>s;
        while( i<nums1.size() && j<nums2.size() ) {
            if(nums1[i] <= nums2[j]) {
                s.push_back(nums1[i]);
                i++;
            }
            else {
                s.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()) {
            s.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()) {
            s.push_back(nums2[j]);
            j++;
        }
        long int m = s.size()/2;
        if(s.size() % 2 == 0) return (float)(s[m] + s[m-1])/2;
        return s[m];
    }
};