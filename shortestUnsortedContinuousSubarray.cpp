#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int end = -1;
        int max = nums[0];
        for (int i = 0; i < n; i++) {
            if (max > nums[i]) end = i;
            else max = nums[i];
        }

        int start = 0;
        int min = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (min < nums[i]) start = i;
            else min = nums[i];
        }

        return end - start + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 2};
    int ans = sol.findUnsortedSubarray(nums);
    cout << ans;
    return 0;
}
