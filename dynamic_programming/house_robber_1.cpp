#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int robber(vector<int>& nums, int i, int l, unordered_map<int, int>& hmap) {
        if(i > l) return 0;
        if(hmap.find(i) != hmap.end()) return hmap[i];
        
        int exclude = robber(nums, i+1, l, hmap);
        int include = nums[i] + robber(nums, i+2, l, hmap); 

        int s = max(include, exclude);
        hmap.insert({i, s});
        return s;
    }
    int rob(vector<int>& nums) {
        int l = nums.size() - 1;
        unordered_map<int, int>hmap;
        return robber(nums, 0, l, hmap);
    }
};