#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) { 
    return a.first < b.first; 
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndex.push_back(make_pair(nums[i], i));
        }
        sort(numsWithIndex.begin(), numsWithIndex.end(), comp);
        int right = numsWithIndex.size() - 1;
        int left = 0;
        int sum;
        while (left < right) {
            sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) return {numsWithIndex[left].second, numsWithIndex[right].second};
            else if (sum < target) left++;
            else right --;
        }
        return {0, 0};
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a {3, 2, 4};
    Solution s;
    vector<int> ans = s.twoSum(a, 6);
    // cout << ans[0] << " " << ans[1] << endl;
    return 0;
}


