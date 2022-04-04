#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if (m*n != r*c) return mat;

        vector<int> vec(m*n);
        int k = 0;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vec[k] = mat[i][j]; 
                k++;
            }
        }

        vector<vector<int>> ans(r, vector<int>(c));
        k = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = vec[k];
                k++;
            }
        }
        return ans;
    }
};