#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:

    double solve(int poured, int row, int col, vector<vector<double>> &dp) {
        if (col < 0 || row < 0 || col > row) return 0.0;

        if (row == 0 && col == 0) return poured;
        if (dp[row][col] > -1) return dp[row][col];
        double left = (solve(poured, row - 1, col - 1, dp) - 1) / 2.0;
        left = max(left, 0.0);
        double right = (solve(poured, row - 1, col, dp) - 1) / 2.0;
        right = max(right, 0.0);

        return dp[row][col] = (left + right);
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101, -1));
        return min(solve(poured, query_row, query_glass, dp), 1.0);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int ans = s.champagneTower(25, 6, 1);
    cout << ans << endl;
    return 0;
}
