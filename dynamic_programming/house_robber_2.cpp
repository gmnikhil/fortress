#include<iostream>
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
        
        if(l == 0) return nums[0];
        
        unordered_map<int, int>hmap1, hmap2;

        int without_first = robber(nums, 1, l, hmap1);
        int without_last = robber(nums, 0, l-1, hmap2);
        return max(without_first, without_last);
    }
};