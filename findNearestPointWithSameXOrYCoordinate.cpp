#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int manhattan(vector<int> &p1, vector<int> &p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int minDist = 1e5;
        int n = points.size();
        vector<int> curr = {x, y};
        for (int i = 0; i < n; i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int tempDist = manhattan(curr, points[i]);
                if (tempDist < minDist) {
                    minDist = tempDist;
                    ans = i;
                }
            } 
        }
        return ans;
    }
};