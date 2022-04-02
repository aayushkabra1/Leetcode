#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while(l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    cout << sol.searchInsert(nums, 2);
    return 0;
}
