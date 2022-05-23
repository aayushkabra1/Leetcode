#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    pair<int, int> count(const string &s) {
        int zeros = 0, ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
            else zeros++;
        }
        return {zeros, ones};
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
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

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> strs = {"10","0001","111001","1","0"};
    int m = 5, n = 3;
    cout << sol.findMaxForm(strs, m, n);
    return 0;
}
