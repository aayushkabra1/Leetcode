#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = nums[0];
        vector<int> freq(10001, 0);

        for (int i : nums) {
            maxNum = max(maxNum, i);
            freq[i] += i;
        }
        int curr = freq[1], prev = 0;
        for (int i = 1; i <= maxNum; i++) {
            int temp = curr;
            curr = max(prev + freq[i], curr);
            prev = curr;
        }
        return curr;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {2,2,3,3,3,4};
    cout << s.deleteAndEarn(nums);
    return 0;
}
