#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     static bool cmp(int a, int b) {
//         return (a % 2) < (b % 2);
//     }

//     vector<int> sortArrayByParity(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), cmp);
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            if (nums[right] % 2 == 0) swap(nums[left++], nums[right]);
            else right--;
        }
        return nums;
    }
};