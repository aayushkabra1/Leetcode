#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(), nums.end());
//     }
// };

//Approach 2
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int peak = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) {
                peak = i;
                break;
            }
        }

        if (peak == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int i;
        for (i = n - 1; i > peak; i--) {
            if (nums[i] > nums[peak]) {
                break;
            }
        }
        swap(nums[peak], nums[i]);
        reverse(nums.begin() + peak + 1, nums.end());
    }
};