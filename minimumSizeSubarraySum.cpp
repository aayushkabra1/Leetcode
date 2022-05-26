#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int start = 0;
        int sum = 0;
        int end = 0;
        while(end < nums.size()) {
            while(sum < target && end < nums.size()) {
                sum += nums[end++];
            }   
            while(sum >= target) {
                ans = min(ans, end - start);
                sum -= nums[start++];
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 15;
    cout << sol.minSubArrayLen(target, nums);
    return 0;
}
