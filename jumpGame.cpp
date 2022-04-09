#include <vector>
using namespace std;

class Solution {
public:
    bool util(vector<int> &dp, int i, vector<int> &nums) {
        if (dp[i] != -1) return dp[i];
        int ans = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (i - j <= nums[j]) {
                ans = util(dp, j, nums);
                if (ans == 1) return dp[i] = ans;
            }
        }
        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 1;
        return util(dp, n - 1, nums);
    }
};