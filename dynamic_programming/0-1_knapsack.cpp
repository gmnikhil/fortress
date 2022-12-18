#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int knapsack(vector<int>v, vector<int>w, int c, int n) {
	if(c==0 || n<0) return 0;
	if(c-w[n] >= 0) {
		return max(v[n]+knapsack(v, w, c-w[n], n-1), knapsack(v, w, c, n-1));
	} 
	return knapsack(v, w, c, n-1);
}

int knapsackDP(vector<int>v, vector<int>w, int n, int c) {
    vector<int>t(c+1, 0);
    vector<vector<int>>dp(n+1, t);
    for(int i=1; i<=n; i++) {
        if(i-w[i-1] >= 0) {
            dp[1][i] = v[i-1];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=c; j++) {
            if(j-w[i-1] >= 0) {
                dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][c];
}

int main() {
	int n, c;
	cin>>n>>c;
	vector<int>v, w;
	for(int i=0; i<n; i++) {
		int t;
		cin>>t;
		v.push_back(t);
	}
	for(int i=0; i<n; i++) {
		int t;
		cin>>t;
		w.push_back(t);
	}
	//cout<<knapsack(v, w, c, n-1);
	cout<<knapsackDP(v, w, n, c);
}