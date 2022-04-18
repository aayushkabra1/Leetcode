#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int util(vector<int> &nums, int low, int high) {
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == nums[high]) high--;
            else if (nums[mid] < nums[high]) high = mid;
            low = mid + 1;
        }
        return nums[high];
    }

    int findMin(vector<int>& nums) {
        return util(nums, 0, nums.size() - 1);
    }
};