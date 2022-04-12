#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> nextState(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int live = 0;
                if (i < n - 1) live += board[i + 1][j]; 
                if (i > 0) live += board[i - 1][j];
                if (j < m - 1) live += board[i][j + 1];
                if (j > 0) live += board[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0) live += board[i - 1][j - 1];
                if (i - 1 >= 0 && j + 1 < m) live += board[i - 1][j + 1];
                if (i + 1 < n && j + 1 < m) live += board[i + 1][j + 1];
                if (i + 1 < n && j - 1 >= 0) live += board[i + 1][j - 1];

                if (board[i][j]) {
                    nextState[i][j] = (live >= 2 && live <= 3);
                }
                else {
                    nextState[i][j] = (live == 3);
                }
            }
        }
        board = nextState;
    }
};