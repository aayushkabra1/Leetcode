#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxTillNow = nums[0];
        int minTillNow = nums[0];
        int ans = nums[0], n = nums.size();

        for (int i = 1; i < n; i++) {
            int temp = max({maxTillNow * nums[i], minTillNow * nums[i], nums[i]});
            minTillNow = min({minTillNow * nums[i], maxTillNow * nums[i], nums[i]});
            maxTillNow = temp;
            ans = max(ans, maxTillNow);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {-4, -3, -2};
    cout << sol.maxProduct(nums);
    return 0;
}
