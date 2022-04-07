#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = 0, prev2 = 0;
        for (int i = 2; i < n + 1; i++) {
            int temp = prev;
            prev = min(cost[i - 2] + prev2, cost[i - 1] + prev);
            prev2 = temp;
        }
        return prev;
    }
};