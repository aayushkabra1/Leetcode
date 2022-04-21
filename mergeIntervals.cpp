#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (tempInterval[1] >= intervals[i][0]) {
                tempInterval[1] = max(intervals[i][1], tempInterval[1]);
            }
            else {
                ans.push_back(tempInterval);
                tempInterval = intervals[i];
            }
        }
        ans.push_back(tempInterval);
        return ans;
    }
};