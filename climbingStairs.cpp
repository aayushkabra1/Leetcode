#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWays(vector<int> &dp, int i) {
        if (i == 1 || i == 2) return i;
        if (dp[i] != -1) return dp[i];
        return (dp[i] = numberOfWays(dp, i - 1) + numberOfWays(dp, i - 2));
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return numberOfWays(dp, n);
    }
};