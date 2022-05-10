#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    void util(int k, int n, vector<int> &combination, int num) {
        if (k == 0) {
            if(accumulate(combination.begin(), combination.end(), 0) == n) {
                ans.push_back(combination);
            }
            return;
        }

        if (num > 9) return;

        combination.push_back(num);
        util(k - 1, n, combination, num + 1);
        combination.pop_back();
        util(k, n, combination, num + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        util(k, n, combination, 1);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> ans = sol.combinationSum3(k, n);
    return 0;
}
