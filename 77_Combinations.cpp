#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> &comb;
    void helper(int k, int n) {
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                this->comb.push_back(i);
                this->ans.push_back(comb);
                this->comb.pop_back();
            }
            return;
        }
        for(int i = n; i >= k; i--) {
            this->comb.push_back(i);
            helper(k - 1, i - 1);
            this->comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        helper(k, n);
        return ans;
    }
};