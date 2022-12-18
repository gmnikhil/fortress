#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int cutRod(vector<int>& rod, int n, unordered_map<int, int>& hmap) {
    if(n == 0) return 0;
    int q = -100;
    for(int i=0; i<n; i++) {
        if(hmap.find(n-i-1)!=hmap.end()) 
            q = max(q, rod[i] + hmap[n-i-1]);
        else
            q = max(q, rod[i] + cutRod(rod, n-i-1, hmap));
    }
    hmap.insert({n, q});
    return q;
}

//does'nt work bcoz el won't be repeated more than once
//ie, if knapsack takes an el, it removes it from rem options to take
int altCut(vector<int>& rod, int n, int c) {
    if(n<0 || c==0) return 0;
    if(c-(n+1)>=0) {
        return max(rod[n] + altCut(rod, n-1, c-(n+1)), altCut(rod, n-1, c));
    } 
    return altCut(rod, n-1, c);
}

//so heres the modified version that works!
int altCutModified(vector<int>& rod, int n, int c) {
    if(n<0 || c==0) return 0;
    if(c-(n+1)>=0) {
        int include = rod[n] + altCutModified(rod, n, c-(n+1));
        int exclude = altCutModified(rod, n-1, c);
        return max(include, exclude);
    } 
    return altCutModified(rod, n-1, c);
}

int cutRodDP(vector<int>& rod, int n, int c) {
    vector<int>t(c+1, 0);
    vector<vector<int>>dp(n+1, t);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=c; j++) {
            if(j-i >= 0) {
                dp[i][j] = max(rod[i-1]+dp[i][j-i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][c];
}

int main() {
    vector<int> p = {3, 5, 8, 9, 10, 35, 17, 20, 24, 30};
    unordered_map<int, int>hmap;
    int x = cutRod(p, 10, hmap);
    int y = altCut(p, 9, 10);
    int z = altCutModified(p, 9, 10);
    int dp = cutRodDP(p, 10, 10);
    cout<<x<<"\n";
    cout<<y<<"\n";
    cout<<z<<"\n";
    cout<<dp;
}