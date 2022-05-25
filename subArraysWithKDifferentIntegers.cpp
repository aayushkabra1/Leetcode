#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int atMost(vector<int> &nums, int k){
        int n = nums.size();
        int ans = 0;
        int start = 0, end = 0;
        unordered_map<int,int> mp;
    
        while(end < n){
            mp[nums[end]]++;
        
            while(mp.size() > k){
                mp[nums[start]]--;
                if(mp[nums[start]] == 0)
                    mp.erase(nums[start]);
                start++;
            }
            ans += end - start + 1;
            end++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << sol.subarraysWithKDistinct(nums, k);
    return 0;
}
