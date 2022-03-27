#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int first(vector<int> &nums, int target, int low, int high) {
        int mid = (low + high) / 2;
        if (low <= high) {
            if ((mid == 0 || target > nums[mid - 1]) && target == nums[mid]) {
                return mid;
            }
            if (target > nums[mid]) return first(nums, target, mid + 1, high);
            return first(nums, target, low, mid - 1);
        }
        return -1;
    }

    int last(vector<int> &nums, int target, int low, int high) {
        int mid = (low + high) / 2;
        if (low <= high) {
            if ((mid == nums.size() - 1 || target < nums[mid + 1]) && target == nums[mid]) {
                return mid;
            }
            if (target < nums[mid]) return last(nums, target, low, mid - 1);
            return last(nums, target, mid + 1, high);
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        return {first(nums, target, 0, n - 1), last(nums, target, 0, n - 1)};
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums ={5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = sol.searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
