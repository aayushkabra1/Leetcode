#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ans;

        int n1 = min((int)nums1.size(), k);
        int n2 = min((int)nums2.size(), k);
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                int sum = nums1[i] + nums2[j];
                pair<int, pair<int, int>> p = make_pair(sum, make_pair(nums1[i], nums2[j]));
                if (pq.size() < k) pq.push(p);
                else if(sum < pq.top().first){
                    pq.pop();
                    pq.push(p);
                }else break;
            }
        }

        while(!pq.empty()) {
            auto temp = pq.top();
            ans.push_back({temp.second.first, temp.second.second});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};