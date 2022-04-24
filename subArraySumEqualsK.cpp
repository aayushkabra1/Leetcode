#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << sol.subarraySum(nums, k);
    return 0;
}
