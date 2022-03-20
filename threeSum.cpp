#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<pair<int, int>> twoSum(vector<int> &nums, int first, int target) {
        vector<pair<int, int>> ans;
        for (int i = first; i < nums.size(); i++) {
            int valueToFind = target - nums[i];
            if (binary_search(nums.begin() + first, nums.end(), valueToFind)) {
                ans.push_back(make_pair(nums[i], valueToFind));
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i <= nums.size(); i++) {
            if (nums[i] > 0) break;
            int target = 0-nums[i];
            vector<pair<int, int>> v = twoSum(nums, i + 1, target);
            for (int i = 0; i < v.size(); i++) {
                ans.push_back({nums[i], v[i].first, v[i].second});
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> ans = s.threeSum(a);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
