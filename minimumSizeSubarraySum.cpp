#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = nums.size();
        int start = 0;
        int sum = 0;
        int end = 0;
        
        while(end < nums.size()) {
            while(sum < target) {
                sum += nums[end++];
            }   
            while(sum > target) {
                ans = min(ans, end - start);
                sum -= nums[start++];
            }
        }
        return ans;
    }
};