#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int pos = 0, neg = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                pos++;
                if (neg) neg++;
            }
            else if (nums[i] < 0) {
                swap(pos, neg);
                neg++;
                if (pos) pos++;
            }
            else {
                pos = 0; neg = 0;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};