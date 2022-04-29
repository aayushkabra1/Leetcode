#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()) {
                    int node = q.front(); q.pop();
                    for (int neighbour : graph[node]) {
                        if (color[neighbour] == -1) {
                            color[neighbour] = 1 - color[node];
                            q.push(neighbour);
                        }
                        else if (color[node] == color[neighbour]) return false;
                    }
                }
            }
        }
        return true;
    }
};