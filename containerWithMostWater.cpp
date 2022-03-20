#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while(left < right) {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            left++;
            ans = max(ans, min(height[left], height[right]) * (right - left));
            right--; left--;
            ans = max(ans, min(height[left], height[right]) * (right - left));
            left++;
            ans = max(ans, min(height[left], height[right]) * (right - left));
        }
        return ans;
    }
};