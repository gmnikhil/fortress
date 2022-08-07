#include<iostream>
#include<vector>

using namespace std;

void inputVector(vector<int> &nums, int s) {
    int t;
    for(int i=0; i<s; i++) {
        cin>>t;
        nums.push_back(t);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    vector<int>v;
    
    inputVector(v, n);
    
    return 0;
}