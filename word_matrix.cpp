#include<iostream>
#include<vector>
#include<string>

using namespace std;

void recurse(vector<vector<char>>& v, int i, int j, string& word, int& p, int l) {
    if(i > l-1 || j > l-1 || i < 0 || j < 0 || v[i][j] == '*')    
        return;

    if(tolower(v[i][j]) == word[p]) {
        v[i][j] = '*';
        p++;
        if(i>0) {
            if(tolower(v[i-1][j]) == word[p]) {
                recurse(v, i-1, j, word, p, l);
                return;
            }
        }
        if(j>0) {
            if(tolower(v[i][j-1]) == word[p]) {
                recurse(v, i, j-1, word, p, l);
                return;
            }
        }
        if(i<l-1) {
            if(tolower(v[i+1][j]) == word[p]) {
                recurse(v, i+1, j, word, p, l);
                return;
            }
        }
        if(j<l-1) {
            if(tolower(v[i][j+1]) == word[p]) {
                recurse(v, i, j+1, word, p, l);
                return;
            }
        }
    }
}

void find(vector<vector<char>>& v, string& word, int& p, int l) {
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[0].size(); j++) {
            if(v[i][j] == word[p]) {
                recurse(v, i, j, word, p, l);
                break;
            }
        }
    }
    if(p == l)  {
        cout<<"found\n\n";
        for(vector<char> x:v) {
            for(char c:x) cout<<c<<" ";
            cout<<"\n";
        }
    }
    else
    cout<<"not found";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<char>>v = { 
        {'o', 'f', 'l', 'k', 'i'},
        {'U', 'm', 'e', 't', 'r'},
        {'n', 'd', 'z', 'u', 'b'},
        {'q', 's', 'v', 'h', 'c'},
        {'x', 'j', 'w', 'y', 'p'}
    };

    string word = "zuvh";
    int p = 0;
    int l = word.length();
    find(v, word, p, l);
    return 0;
}