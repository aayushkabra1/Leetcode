#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int solve(int n, vector<int> &dp) {
        if (dp[n] != -1) return dp[n];
        long res = solve(n - 1, dp);
        res *= (2*n - 1);
        res *= n;
        return dp[n] = res % 1000000007;
        //return dp[n] = (((solve(n - 1, dp)%1000000007) * (2*n - 1)%1000000007) * (n)) % 1000000007;
    }

    int countOrders(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        return solve(n, dp);
    }
};