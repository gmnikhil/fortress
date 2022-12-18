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

int main() {
    vector<int> p = {3, 5, 8, 9, 10, 35, 17, 20, 24, 30};
    unordered_map<int, int>hmap;
    int x = cutRod(p, 10, hmap);
    int y = altCut(p, 9, 10);
    cout<<x<<"\n";
    cout<<y;
}