#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int n = numbers.size();
        int r = n - 1;
        int sum;
        while(l < r) {
            sum = numbers[l] + numbers[r];
            if (sum < target) l++;
            else if (sum > target) r--;
            else return {l + 1, r + 1};
        }
        return {-1, -1};
    }
};
