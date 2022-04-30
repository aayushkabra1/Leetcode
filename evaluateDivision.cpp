#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, int> visited;
    double query;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
            visited[equations[i][0]] = 0; visited[equations[i][1]] = 0;
        }

        int m = queries.size();
        vector<double> ans(m, -1);
        for (int i = 0; i < m; i++) {
            query = 1;
            if (dfs(queries[i][0], queries[i][1], 1)) {
                ans[i] = query;
            }
        }
        return ans;
    }

    bool dfs(string &start, string &end, double prod) {
        if (start == end && adj.find(start) != adj.end()) {
            query = prod;
            return true;
        }

        bool temp = false;
        visited[start] = 1;
        for (int i = 0; i < adj[start].size(); i++) {
            if (!visited[adj[start][i].first]) {
                temp = dfs(adj[start][i].first, end, prod * adj[start][i].second);
                if (temp) break;
            }
        }
        visited[start] = false;
        return temp;
    }
};