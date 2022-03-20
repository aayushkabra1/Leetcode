#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<int>> &visited) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j] == 1) return;
        visited[i][j] = 1;
        dfs(i + 1, j, m, n, grid, visited);
        dfs(i - 1, j, m, n, grid, visited);
        dfs(i, j + 1, m, n, grid, visited);
        dfs(i, j - 1, m, n, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && grid[i][j] == '1') {
                    dfs(i, j, m, n, grid, visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};