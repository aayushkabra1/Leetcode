#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        for (int i : nums1) mp1[i]++;
        for (int i : nums2) mp2[i]++;
        vector<int> ans;
        unordered_map<int, int>::iterator itr = mp1.begin();
        for (itr; itr != mp1.end(); itr++) {
            int freq = min(itr->second, mp2[itr->first]);
            for (int i = 0; i < freq; i++) {
                ans.push_back(itr->first);
            }
        }
        return ans;
    }
};