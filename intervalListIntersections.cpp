#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        vector<vector<int>> ans;
        int p1 = 0, p2 = 0;

        while(p1 < n && p2 < m) {
            int start1 = firstList[p1][0], end1 = firstList[p1][1];
            int start2 = secondList[p2][0], end2 = secondList[p2][1];
            if (max(start1, start2) <= min(end1, end2)) {
                ans.push_back({max(start1, start2), min(end1, end2)});
            }
            if (end1 > end2) p2++;
            else p1++;
        }
        return ans;
    }
};