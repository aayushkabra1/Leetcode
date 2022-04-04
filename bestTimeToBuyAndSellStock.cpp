#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxDiff = prices[1] - prices[0], minPrice = prices[0], n = prices.size();
        for (int i = 1; i < n; i++) {
            maxDiff = max(maxDiff, prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }
        return maxDiff;
    }
};