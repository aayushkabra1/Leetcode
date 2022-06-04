#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmallestEl(vector<int> &nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while(!st.empty() && nums[i] <= nums[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 2, 1, 5, 6, 3, 2, 4, 4};
    vector<int> ans = prevSmallestEl(nums);
    return 0;
}
