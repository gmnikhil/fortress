#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>

using namespace std;

bool appendAndDelete(string s, string t, int k, unordered_set<char>& uc) {
    if(k<0) return false;
    if(s == t && k == 0) return true;
    
    bool b = false;
    if(s.length() < t.length()) {
        for(char c:uc) {
            b = appendAndDelete(s+c, t, k-1, uc);
            if(b) break;
        }
    }
    if(!b) {
        if(s.length() != 0)
            s.pop_back();
        b = appendAndDelete(s, t, k-1, uc);
    }
    return b;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    string s, t;
    int k;
    cin>>s;
    cin>>t;
    cin>>k;
    
    unordered_set<string>visited;
    unordered_set<char>uc;
    for(char c : t) {
        uc.insert(c);
    }

    bool possible = appendAndDelete(s, t, k, uc);
    
    if(possible) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}