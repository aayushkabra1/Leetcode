#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        int inHand = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] > inHand) ans += prices[i] - inHand;
            inHand = prices[i];
        }
        return ans;
    }
};