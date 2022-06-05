#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int i, vector<int> &nums) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        solve(ans, temp, i + 1, nums);
        temp.pop_back();
        solve(ans, temp, i + 1, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp;
        solve(ans, temp, 0, nums);
        return ans;
    }
};