#include <vector>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans = 0;
                break;
            }
            if (nums[i] < 0) {
                ans = -ans;
            }
        }
        return ans;
    }
};