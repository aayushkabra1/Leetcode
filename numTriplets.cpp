#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long, long> mp1, mp2;

        for (int i = 0; i < nums1.size() - 1; i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                mp1[(long)nums1[i] * nums1[j]]++;
            }
        }

        for (int i = 0; i < nums2.size() - 1; i++) {
            for (int j = i + 1; j < nums2.size(); j++) {
                mp1[(long)nums2[i] * nums2[j]]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            ans += mp2[(long)nums1[i]*nums1[i]];
        }

        for (int i = 0; i < nums2.size(); i++) { 
            ans += mp2[(long)nums2[i]*nums2[i]];
        }
        return ans;
    }
};