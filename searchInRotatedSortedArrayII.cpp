#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search_(vector<int> nums, int low, int high, int target) {
        if (low > high) return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;

        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++; high--;
            return search_(nums, low, high, target);
        }
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

    bool search(vector<int>& nums, int target) {
        int index = search_(nums, 0, nums.size() - 1, target);
        return (index >= 0 && index < nums.size());
    }
};