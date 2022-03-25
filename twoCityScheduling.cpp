#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int costToA = 0;
        vector<int> difference(n, 0);

        for (int i = 0; i < n; i++) {
            costToA += costs[i][0];
            difference[i] = costs[i][1] - costs[i][0];
        }

        sort(difference.begin(), difference.end());
        for (int i = 0; i < n/2; i++) {
            costToA += difference[i];
        }
        return costToA;
    }
};