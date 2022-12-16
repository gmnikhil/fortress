#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    bool recMemo(string s, vector<string>& wordDict, int l, int sp, unordered_set<int>& hm) {
        if(sp == l) return true;
        bool f = false;
        if(hm.find(sp) == hm.end()) {
            for(string w:wordDict) {
                if(s.substr(sp, w.length()) == w) {
                    f = recMemo(s, wordDict, l, sp + w.length(), hm);
                    if(f) break;
                }
            }
            hm.insert(sp);
        }
        return f;
    }

    bool bfsMemo(string s, vector<string>& wordDict, unordered_set<int>& hm) {
        int start = 0;
        int l = s.length();
        queue<int>q;
        q.push(start);
        while(!q.empty()) {
            int idx = q.front();
            if(idx == l) return true;
            if(hm.find(idx) == hm.end()) {
                for(string w:wordDict) {
                    if(s.substr(idx, w.length()) == w) {
                        q.push(idx+w.length());
                    }
                }
                hm.insert(idx);
            } 
            q.pop();
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int sp = 0;
        int l = s.length();
        unordered_set<int>hm;

        //bool ans = bfsMemo(s, wordDict, hm);
        bool ans = recMemo(s, wordDict, l, sp, hm);

        return ans;
    }
};