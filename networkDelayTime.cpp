#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

    void dijkstra(vector<vector<int>> &adj, vector<int> &dist, vector<int> &vis, int src) {
        set<pair<int, int>> pq;
        pq.insert({0, src});

        while(!pq.empty()) {
            auto node = *pq.begin();
            int v = node.second;
            int w = node.first;
            for (int neighbour : adj[v]) {
                int neighbout_v = neighbour[1];
                
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX - 1);
        vector<int> visited(n, 0);
        dist[k] = 0;
    }
}