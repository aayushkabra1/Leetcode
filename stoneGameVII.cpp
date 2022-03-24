#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int stoneGameVII_(vector<int> &stones, vector<vector<int>> &dp, int s, int e, int sum) {
        if (s > e) return 0;
        if (dp[s][e] != -1) return dp[s][e];
        
        int left = sum - stones[s] - stoneGameVII_(stones, dp, s + 1, e, sum - stones[s]);
        int right = sum - stones[e] - stoneGameVII_(stones, dp, s, e - 1, sum - stones[e]);

        return dp[s][e] = max(left, right);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int i : stones) sum += i;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return stoneGameVII_(stones, dp, 0, n - 1, sum);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> stones = {5, 3, 1, 4, 2};
    cout << sol.stoneGameVII(stones) << endl;
    return 0;
}
