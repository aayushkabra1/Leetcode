#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int index = 0, n = nums.size();
        map<int, int, greater<int>> mp;
        
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
        vector<int> ans;
        ans.push_back(mp.begin()->first);

        for (int i = k; i < n; i++) {
            mp[nums[i]]++;
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
            ans.push_back(mp.begin()->first);
        }
        return ans;
    }
};