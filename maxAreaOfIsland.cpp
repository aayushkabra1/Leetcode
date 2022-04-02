#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void visit(vector<vector<int>> &grid, int r, int c, int &lastArea) {
        int n = grid.size();
        int m = n ? grid[0].size():0;
        if (r < 0 || c < 0 || r >= n || c >= m) return;
        if (grid[r][c] == 0) return;
        grid[r][c] = 0;  
        lastArea++;
        visit(grid, r + 1, c, lastArea);
        visit(grid, r, c + 1, lastArea);
        visit(grid, r - 1, c, lastArea);
        visit(grid, r, c - 1, lastArea);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n ? grid[0].size():0;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int temp = 0;
                if (grid[i][j]) {
                    visit(grid, i, j, temp);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};