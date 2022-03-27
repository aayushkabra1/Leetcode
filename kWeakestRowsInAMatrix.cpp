#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        set<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            int cnt = count(mat[i].begin(), mat[i].end(), 1);
            s.insert(make_pair(cnt, i));
        }

        set<pair<int, int>>::iterator itr = s.begin();
        vector<int> ans(k, 0);
        for (int i = 0; i < k; i++) {
            ans[i] = itr->second;
            itr++;
        }
        return ans;
    }
};