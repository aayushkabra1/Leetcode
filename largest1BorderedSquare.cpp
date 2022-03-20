#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> vertical(n, vector<int>(m, 0));
        vector<vector<int>> horizontal(n, vector<int>(m, 0));
        vertical[0][0] = horizontal[0][0] = (grid[0][0] == 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int one = (grid[i][j] == 1);
                
                horizontal[i][j] = (j == 0) ? one : horizontal[i][j - 1] + one;
                vertical[i][j] = (i == 0) ? one : vertical[i - 1][j] + one;
            }
        }
    }
};