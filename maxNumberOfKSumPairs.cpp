#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         map<int, int> freq;
//         for (int i : nums) freq[i]++;

//         map<int, int>::iterator itr = freq.begin();
//         int ans = 0;
//         for (itr; itr != freq.end(); itr++) {
//             int x = itr->first;
//             if (x > k / 2) break;
//             if ((double)x == k / 2.0) ans += freq[x] / 2;
//             else ans += min(itr->second, freq[k - itr->first]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, start = 0, end = nums.size() - 1;
        while(start < end) {
            if (nums[start] + nums[end] == k) {
                ans++;
                start++;
                end--;
            }
            else if (nums[start] + nums[end] > k) {
                end--;
            }
            else {
                start++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    cout << sol.maxOperations(nums, 5);
    return 0;
}
