#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        for (int i = 1; i < numRows; i++) {
            ans[i].push_back(1);

            int j = 0;
            while(j < ans[i - 1].size() - 1) {
                ans[i].push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
                j++;
            }

            ans[i].push_back(1);
        }
        return ans;
    }
};