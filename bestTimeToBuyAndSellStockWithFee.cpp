#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> bought(n), sold(n);
        bought[0] = 0, sold[0] = -prices[0];

        for(int i = 1; i < n; i++) {
            bought[i] = max(bought[i - 1], sold[i - 1] + prices[i] - fee);
            sold[i] = max(sold[i - 1], bought[i - 1] - prices[i]);
        }
        return bought.back();
    }
};