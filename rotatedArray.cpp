#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int getPivot(vector<int> &nums) {
        int left = 0;
        int right = nums.size();
        int pivotIndex = (left + right)/2;
        if (nums[pivotIndex] > nums[pivotIndex + 1]) return pivotIndex;
        if (nums[pivotIndex - 1] > nums[pivotIndex]) return pivotIndex-1;
        if ()
    }

    int search(vector<int>& nums, int target) {
        
    }
};