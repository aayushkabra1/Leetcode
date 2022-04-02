#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k % n;
    //     vector<int> nums2(nums.begin(), nums.end());
    //     for (int i = 0; i < n; i++) {
    //         nums[(i + k) % n] = nums2[i];
    //     }
    // }

    void flip(vector<int> &nums, int l, int r) {
        while(l < r) {
            swap(nums[l], nums[r]);
            l++; r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        flip(nums, 0, n - 1);
        flip(nums, 0, k - 1);
        flip(nums, k, n - 1);        
    }
};