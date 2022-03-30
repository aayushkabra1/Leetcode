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
//                 newMatrix[q * m + t] = matrix[q][t];
//             }
//         }
//         return binary_search(newMatrix.begin(), newMatrix.end(), target);
//     }
// };

