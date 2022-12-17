#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int twoPointer(vector<int> height, int n) {
        int l = 0;
        int r = n-1;
        int area = 0;
        while(l<r) {
            if(height[l] < height[r]) {
                area = max(height[l]*(r-l), area);
                l++;
            } else {
                area = max(height[r]*(r-l), area);
                r--;
            }
        }
        return area;
    }

    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int h = min(height[i], height[j]);
                area = max((j-i)*h, area);
            }
        }
        
        //return twoPointer(height, n);

        return area;
    }
};