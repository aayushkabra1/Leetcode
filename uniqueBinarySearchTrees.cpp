#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if (n == 0 || n == 1) return 1;
        if (n == 2) return 2;
        if (dp[n]) return dp[n];
        int count = 0;
        for(int i = 0; i < n; i++){
            count += solve(i,dp) * solve(n - i - 1, dp);
        }
        dp[n] = count;
        return dp[n];
    }

    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        return solve(n, dp);
    }
};