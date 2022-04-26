#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(int i, int target, vector<int> &nums2) {
        int end = nums2.size() - 1, start = i;
        int curr = 0;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (i <= mid && target <= nums2[mid]) {
                curr = mid - i;
            }
            if (target <= nums2[mid]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return curr;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = min(nums1.size(), nums2.size());
        for (int i = 0; i < n; i++) {
            ans = max(ans, binarySearch(i, nums1[i], nums2));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums1 = {55,30,5,4,2};
    vector<int> nums2 = {100,20,10,10,5};
    cout << sol.maxDistance(nums1, nums2);
    return 0;
}
