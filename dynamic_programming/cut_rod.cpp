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

int main() {
    vector<int> p = {1, 5, 8, 9, 10, 35, 17, 20, 24, 30};
    unordered_map<int, int>hmap;
    int x = cutRod(p, 10, hmap);
    cout<<x;
}