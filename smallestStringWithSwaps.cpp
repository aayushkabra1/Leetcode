#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(int v, vector<int> &index, vector<char> &letters, string &s, vector<vector<int>> &adj, vector<int> &visited) {
        visited[v] = 1;
        letters.push_back(s[v]);
        index.push_back(v);
        for (int vertex : adj[v]) {
            if (!visited[vertex]) {
                dfs(vertex, index, letters, s, adj, visited);
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);

        for (vector<int> &pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        for (int i = 0; i < n; i++) {
            vector<int> index;
            vector<char> letters;
            if (!visited[i]) {
                dfs(i, index, letters, s, adj, visited);
            }

            sort(index.begin(), index.end());
            sort(letters.begin(), letters.end());
            int m = index.size();
            for (int j = 0; j < m; j++) {
                s[index[j]] = letters[j];
            }
        }
        return s;
    }
};