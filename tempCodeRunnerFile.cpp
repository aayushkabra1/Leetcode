        }
        return {zeros, ones};
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1];
        int zeros, ones;
        for (string s : strs) {
            pair<int, int> p = count(s);
            zeros = p.first, ones = p.second;

            for (int j = m; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zeros][k - ones]);
                }
            }
        }
        return dp[m][n];
    }
};