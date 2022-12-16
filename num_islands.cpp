#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    void traverse(int i, int j, vector<vector<char>>& grid, int b, int l) {
        if(i<0||j<0||i>b||j>l) return;
        if(grid[i][j] == '1') {
            grid[i][j]='*';
            traverse(i+1, j, grid, b, l);
            traverse(i-1, j, grid, b, l);
            traverse(i, j+1, grid, b, l);
            traverse(i, j-1, grid, b, l);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int c = 0;
        
        int b = grid.size()-1;
        int l = grid[0].size()-1;
        
        for(int i=0; i<=b; i++) {
            for(int j=0; j<=l; j++) {
                if(grid[i][j] == '1') {
                    traverse(i, j, grid, b, l);
                    c++;
                }
            }
        }
        return c;
    }
};