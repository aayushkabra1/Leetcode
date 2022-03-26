#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[i] <= nums[st.top()]) st.push(i);
        }

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[i] >= nums[st.top()]) {
                ans = max(ans, i - st.top());
                st.pop();
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {9,8,1,0,1,9,4,0,4,1};
    cout << sol.maxWidthRamp(nums) << endl;
    return 0;
}
