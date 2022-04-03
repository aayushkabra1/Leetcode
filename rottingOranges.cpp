#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int numberOfOranges = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    numberOfOranges++;
                }
                if (grid[i][j] == 1) {
                    numberOfOranges++;
                }
            }
        }

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int count = 0, ans = 0;
        while(!q.empty()) {
            int size = q.size();
            count += size;

            for (int i = 0; i < size; i++) {
                pair<int, int> node = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int x = node.first + dx[j], y = node.second + dy[j];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }

            if (!q.empty()) ans += 1;
        }
        if (count == numberOfOranges) return ans;
        return -1;
    }
};