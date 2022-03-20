#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool visit(vector<vector<char>> &board, string word, vector<vector<int>> &visited, int x, int y) {
        if (word.size() <= 0) return true;
        if (x < 0 || y < 0 || x > board.size() || y > board[0].size()) return false;
        if (word.size() == 1) return (board[x][y] == word[0]);
        if (board[x][y] == word[0]) {
            visited[x][y] = 1;
            return visit(board, word.substr(1), visited, x + 1, y) ||
                    visit(board, word.substr(1), visited, x, y + 1) ||
                    visit(board, word.substr(1), visited, x - 1, y) ||
                    visit(board, word.substr(1), visited, x, y - 1);
        }
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        vector<string> ans;
        for (string s : words) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (visit(board, s, visited, i, j)) ans.push_back(s);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board;
    board.push_back({'o','a','a','n'});
    board.push_back({'e','t','a','e'});
    board.push_back({'i','h','k','r'});
    board.push_back({'i','f','l','v'});

    vector<string> words = {"oath","pea","eat","rain"};
    Solution s;
    vector<string> ans = s.findWords(board, words);
    for (string a : ans) {
        cout << a << endl;
    }
    return 0;
}