#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        vector<int> ans(k);
        vector<pair<int, int>> vec;
        for (auto &a : freq) {
            vec.push_back({a.first, a.second});
        }
        sort(vec.begin(), vec.end(), cmp);

        for (int i = 0; i < k; i++) {
            ans[i] = (vec[i].first);
        }
        return ans;
    }
};