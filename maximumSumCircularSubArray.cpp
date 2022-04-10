#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kadane(vector<int> &nums) {
        int ans = INT_MIN;
        int maxTillHere = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            maxTillHere += nums[i];
            ans = max(ans, maxTillHere);
            maxTillHere = max(maxTillHere, 0);
        }
        return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int x = kadane(nums);

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            nums[i] *= -1;
        }

        int y = kadane(nums);
        if (sum + y == 0) return x;
        return max(x, sum + y);
    }
};