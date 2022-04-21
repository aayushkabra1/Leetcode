#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        int n = intervals.size(), ans = n - 1;
        int last = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= last) {
                ans--;
                last = intervals[i][1];
            }
        }
        return ans;
    }
};