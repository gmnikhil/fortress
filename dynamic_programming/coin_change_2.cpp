#include<iostream>
#include<queue>
#include<unordered_set>
#include<string>

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
                    string x = curr_amt->cs + to_string(coin);
                    
                    newnode->cs = x;
                    newnode->amt = curr_amt->amt + coin;
                    q.push(newnode);
                }
                visited.insert(curr_amt->cs);
            }
        
        }

        return count;
    }
};

int main() {
    Solution s = Solution();
    vector<int>coins={1,2,5};
    cout<<s.change(500, coins);
}