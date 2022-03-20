#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> mp;

        for (int i = 0; i < 9; i++) {
        	mp.clear();
        	for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                mp[c]++;
                if (mp[c] > 1) return false;
        	}
        }

        for (int i = 0; i < 9; i++) {
        	mp.clear();
        	for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c == '.') continue;
                mp[c]++;
                if (mp[c] > 1) return false;
        	}
        }

        
    }
};