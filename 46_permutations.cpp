#include <vector>
#include <unordered_set>
using namespace std;

// Approach 1
// class Solution {
// public:
//     vector<vector<int>> ans;

//     void helper(vector<int> &nums, vector<int> &temp_ans) {
//         int n = nums.size();
//         if (temp_ans.size() == n) {
//             unordered_set<int> st(temp_ans.begin(), temp_ans.end());
//             bool temp = temp_ans.size() == st.size();
//             if (temp) ans.push_back(temp_ans);
//             return;
//         }
//         for (int i = 0; i < n; i++) {
//             temp_ans.push_back(nums[i]);
//             helper(nums, temp_ans);
//             temp_ans.pop_back();
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<int> temp_ans;
//         helper(nums, temp_ans);
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int> &nums, int i) {
        int n = nums.size();
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = i; i  < n; i++) {
            swap(nums[i], nums[j]);
            helper(nums, j + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp_ans;
        helper(nums, 0);
        return ans;
    }
};