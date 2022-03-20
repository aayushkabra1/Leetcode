#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0, ans = 0, i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) zeroCount++;
            while(zeroCount > k) {
                if (nums[i] == 0) zeroCount--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

