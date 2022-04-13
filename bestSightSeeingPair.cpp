#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), maxSoFar = values[0], ans = -1;
        for (int i = 1; i < n; i++) {
            ans = max(ans, maxSoFar + values[i] - i);
            maxSoFar = max(maxSoFar, values[i] + i);
        }
        return ans;
    }
};