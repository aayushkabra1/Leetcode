#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> newGrid(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int newRow = (i + (j + k) / cols) % rows;
                int newCol = (j + k) % cols;
                newGrid[newRow][newCol] = grid[i][j];
            }
        }        
        return newGrid;
    }
};