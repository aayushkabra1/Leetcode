#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         vector<int> newMatrix(n*m, 0);
//         for (int q = 0; q < n; q++) {
//             for (int t = 0; t < m; t++) {
//                 if (matrix[q][t] == target) return true;
//             }
//         }
//         return false;
//     }
// };

// Approach 2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =  matrix.size();
        int m = matrix[0].size();
        int r = 0;
        int c = m - 1;

        while(r < n && r >= 0 && c >= 0 && c < m) {
            int temp = matrix[r][c];
            if (temp > target) c--;
            if (temp < target) r++;
            if (temp == target) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> matrix = {{1}};
    int target = 0;
    cout << sol.searchMatrix(matrix, target) << endl;
    return 0;
}


