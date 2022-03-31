#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int> &nums, long long mid, int m) {
        int count = 1;
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > mid) {
                count++;
                sum = nums[i];
                if (count > m) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 011);
        
        while(left < right) {
            long long mid = (left + right) / 2;
            if (check(nums, mid, m)) {
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
};