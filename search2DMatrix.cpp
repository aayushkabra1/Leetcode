#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

    bool searchMatrixUtil(vector<vector<int>> &matrix, int target, int fromRow, int fromCol, int toRow, int toCol) {
        if (fromRow == toRow && fromCol == toCol) return (matrix[fromRow][fromCol] == target);
        
        int midRow = (fromRow + toRow) / 2;
        int midCol = (fromCol + toCol) / 2;
        if (matrix[midRow][midCol] == target) return true;
        else if (matrix[midRow][midCol] < target) {
            return searchMatrixUtil(matrix, target, midRow +1, midCol +1, toRow, toCol);
        }
        else if (matrix[midRow][midCol] > target) {
            return searchMatrixUtil(matrix, target, fromRow, fromCol, midRow -1, midCol -1);
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        return searchMatrixUtil(matrix, target, 0, 0, rows - 1, cols - 1);
    }
};