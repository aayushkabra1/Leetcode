#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int m1 = nums[0], m2 = nums[1];
        for (int i = 2; i < n; i++) {
            int temp = max(m2, m1 + nums[i]);
            m1 = max(m2, m1);
            m2 = temp;
        }
        return m2;
    }
};