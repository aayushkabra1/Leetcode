#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0, buyLast = INT_MIN, sell = 0, sellLast = 0, sellLastLast = 0;

        for (int i = 0; i < n; i++) {
            buy = max(buyLast, sellLastLast - prices[i]);
            sell = max(sellLast, buyLast + prices[i]);

            buyLast = buy;
            sellLastLast = sellLast;
            sellLast = sell;
        }
        return sell;
    }
};