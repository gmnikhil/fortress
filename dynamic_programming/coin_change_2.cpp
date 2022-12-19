#include<iostream>
#include<queue>
#include<unordered_set>
#include<string>

#define INT_MAX 2147483647

using namespace std;

class Solution {
public:

    struct Amt {
        long long amt;
        string cs;
    };

    int change(int amount, vector<int>& coins) {
        int count = 0;
        queue<Amt*>q;
        unordered_set<string>visited;
        
        struct Amt *init = new Amt();
        init->amt = 0;
        init->cs = "0";

        int min = amount;
        for(int i=0; i<coins.size(); i++) {
           if(coins[i] < min) min = coins[i];
        }

        if(min>amount) return 0;
        
        q.push(init);

        while(!q.empty()) {
            struct Amt *curr_amt = q.front();
            q.pop();

            if(curr_amt->amt > amount) {
                continue;
            }

            if(curr_amt->amt == amount) {
                if(visited.find(curr_amt->cs) == visited.end()) {
                    count++;
                    //cout<<curr_amt->cs<<"\n";
                    visited.insert(curr_amt->cs);
                }
                continue;
            }
            
            if(visited.find(curr_amt->cs) == visited.end()) {
                for(int coin : coins) {
                    int t = (int)((curr_amt->cs).back() - 48);
                    if(t>coin) continue;

                    struct Amt *newnode = new Amt();
                    newnode->cs = curr_amt->cs + to_string(coin);
                    newnode->amt = curr_amt->amt + coin;
                    q.push(newnode);
                }
                visited.insert(curr_amt->cs);
            }
        
        }

        return count;
    }

    int changeDP(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>t(amount+1, 0);
        vector<vector<int>>dp(n+1, t);

        int min = INT_MAX;
        for(int x:coins) {
            if(x<min) min = x;
        }
        if(min>amount) return 1;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=amount; j++) {
                if(coins[i-1] <= j) {
                    if(coins[i-1] % j == 0) {
                        dp[i][j] = 1 + max(dp[i][j-coins[i-1]], dp[i-1][j]);
                    } else {
                        dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                    }
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount];
    }
};


int main() {
    Solution s = Solution();
    vector<int>coins={1,2,5};
    cout<<s.change(500, coins);
    cout<<"\n";
    cout<<s.changeDP(500, coins);
}