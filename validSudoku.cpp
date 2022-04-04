#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> mp;
        int n = board.size();
        // Check for rows
        for (int i = 0; i < n; i++) {
            mp.clear();
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                mp[board[i][j]]++;
                if (mp[board[i][j]] > 1) return false;
            }
        }

        // Check for columns
        for (int i = 0; i < n; i++) {
            mp.clear();
            for (int j = 0; j < n; j++) {
                if (board[j][i] == '.') continue;
                mp[board[j][i]]++;
                if (mp[board[j][i]] > 1) return false;
            }
        }

        // check for grids
        for (int gi = 0; gi < 9; gi += 3) {
            for (int gj = 0; gj < 9; gj += 3) {
                mp.clear();
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if(board[i + gi][j + gj] == '.') continue;
                        mp[board[i + gi][j + gj]]++;
                        if (mp[board[i + gi][j + gj]] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};