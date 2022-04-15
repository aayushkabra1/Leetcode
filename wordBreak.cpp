#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool util(string &s, vector<string> &dict, vector<int> &dp, int index) {
        int n = s.size();
        if (index == n) return true;
        if (dp[index] != -1) return dp[index];
        int size = dict.size(), ans = 0;
        for (int i = 0; i < size; i++) {
            if (s.substr(index, dict[i].size()) == dict[i]) {
                ans += util(s, dict, dp, index + dict[i].size());
            }
        }
        return dp[index] = (ans != 0);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        return util(s, wordDict, dp, 0);
    }
};