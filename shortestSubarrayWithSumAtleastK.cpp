#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int check(vector<int> &nums, int target, int windowSize) {
        int n = nums.size(), sum = 0;
        if (sum >= target) return 1;
        for (int i = 0; i < windowSize; i++) {
            sum += nums[i];
            if (sum >= target) return 1;
        }

        for (int i = windowSize; i < n; i++) {
            sum -= nums[i - windowSize];
            sum += nums[i];
            if (sum >= target) return 1;
        }
        return 0;
    }
    
    int shortestSubarray(vector<int>& nums, int k) {
        int low = 0, high = nums.size();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (check(nums, k, mid)) high = mid;
            else low = mid + 1;
        }
        return check(nums, k, high) ? high : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {84,-37,32,40,95};
    int k = 167;
    cout << sol.shortestSubarray(nums, k);
    return 0;
}
