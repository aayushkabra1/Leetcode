#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define mp make_pair

class Solution {
public:
    bool inBounds(pair<int, int> &p, int n, int m) {
        return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m);
    }
 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> distMatrix(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j]) {
                    distMatrix[i][j]++;
                    q.push(mp(i, j));
                }
            }
        }
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        while(!q.empty()) {
            pair<int, int> coordinate = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> neighbour = {coordinate.first + dx[i], coordinate.second + dy[i]};
                if (inBounds(neighbour, n, m) && distMatrix[neighbour.first][neighbour.second] == -1) {
                    distMatrix[neighbour.first][neighbour.second] = distMatrix[coordinate.first][coordinate.second] + 1;
                    q.push(neighbour);
                }
            }
        }
        return distMatrix;
    }
};