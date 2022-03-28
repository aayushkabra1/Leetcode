#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search_(vector<int> nums, int low, int high, int target) {
        if (low > high) return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;

        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target <= nums[mid]) {
                return search_(nums, low, mid - 1, target);
            }
            return search_(nums, mid + 1, high, target);
        }
        else {
            if (target >= nums[mid] && target <= nums[high]) {
                return search_(nums, mid + 1, high, target);
            }
            return search_(nums, low, mid - 1, target);
        }
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        return search_(nums, 0, n - 1, target);
    }
};