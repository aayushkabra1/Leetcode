#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n = nums.size(), min = nums[0];
        stack<int> st;
        int mid = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            if (mid > nums[i]) return true;
            while(!st.empty() && nums[i] > st.top()) {
                mid = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};