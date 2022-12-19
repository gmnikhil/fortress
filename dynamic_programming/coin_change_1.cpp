#include<iostream>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    struct Amt {
        int coins;
        long long amt;
    };
    
    int coinChange(vector<int>& coins, int amount) {
        
        queue<Amt*>q;
        unordered_set<long long>visited;
        struct Amt *init = (struct Amt*)malloc(sizeof(struct Amt));
        init->coins = 0;
        init->amt = 0;

        int minCoins = 1000000;

        if(amount == 0) return 0;

        int min = amount;
        for(int i=0; i<coins.size(); i++) {
           if(coins[i] < min) min = coins[i];
        }

        if(min>amount) return -1;

        q.push(init);

        while(!q.empty()) {
            struct Amt *curr_amt = q.front();
            q.pop();
            if(curr_amt->amt > amount || minCoins < curr_amt->coins) continue;
            
            if(curr_amt->amt == amount && minCoins > curr_amt->coins) {
                minCoins = curr_amt->coins;
                continue;
            }
            if(visited.find(curr_amt->amt) == visited.end()) {
           
                for(int coin : coins) {
                   
                    struct Amt *newnode = (struct Amt*)malloc(sizeof(struct Amt));
                    newnode->coins = curr_amt->coins + 1;
                    newnode->amt = curr_amt->amt + coin;
                    q.push(newnode);
                    
                }
               
            } 
            visited.insert(curr_amt->amt);
        }

        if(minCoins == 1000000) return -1;
        return minCoins;
    }

    int coinChangeDP(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        int n = coins.size();
        vector<int>t(amount+1, INT_MAX-1);
        vector<vector<int>>dp(n+1, t);
        
        int smallest = INT_MAX;
        for(int coin:coins) {
            if(coin<smallest) smallest=coin;
        }
        if(smallest>amount) return -1;
        
        for(int i=1; i<=n; i++) {
            dp[i][0]=0;
            for(int j=1; j<=amount; j++) {
                if(j-coins[i-1] >= 0) {
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][amount] == INT_MAX-1) return -1;
        return dp[n][amount];
    }
};