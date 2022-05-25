#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ = -1;
        int maxTillNow = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) maxTillNow++;
            else maxTillNow = 0;
            max_ = max(max_, maxTillNow);            
        }
        return max_;
    }
};

