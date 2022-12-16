#include<iostream>
#include<queue>
#include<unordered_set>
#include<sstream>

using namespace std;

class Solution {
public:

    struct Amt {
        long long amt;
        long long cs;
    };

    int change(int amount, vector<int>& coins) {
        int count = 0;
        queue<Amt*>q;
        unordered_set<long long>visited;
        
        struct Amt *init = (struct Amt*)malloc(sizeof(struct Amt));
        init->amt = 0;
        init->cs = 0;

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
                    visited.insert(curr_amt->cs);
                }
                continue;
            }
            if(visited.find(curr_amt->cs) == visited.end()) {
                for(int coin : coins) {
                    struct Amt *newnode = (struct Amt*)malloc(sizeof(struct Amt));
                    string x = to_string(curr_amt->cs) + to_string(coin);
                    sort(x.begin(), x.end());
                    stringstream ss(x);
                    ss>>newnode->cs;
                    newnode->amt = curr_amt->amt + coin;
                    q.push(newnode);
                }
                visited.insert(curr_amt->cs);
            }
        }
        return count;
    }
};