#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M;

int dijkstra(vector<vector<vector<int>>> &adj, int s) {
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<int> vis(N + 1, 0);
    vector<int> dist(N + 1, INT_MAX);

    dist[s] = 1;
    pq.push({0, s});

    while(!pq.empty()) {
        pair<int, int> temp = pq.top(); pq.pop();
        int node = temp.second, distTillNow = temp.first;
        vis[node] = 1;

        for (auto &v : adj[node]) {
            int neighbour = v[0], w = v[1];
            if (vis[neighbour]) continue;
            if (distTillNow + w < dist[neighbour]) {
                dist[neighbour] = distTillNow + w;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    return dist[N] == INT_MAX ? -1 : dist[N];
}

int main() {
	// your code goes here
	cin >> N >> M;
	
	vector<vector<vector<int>>> adj(N + 1);
	for (int i = 0; i < M; i++) {
	    int x, y;
	    cin >> x >> y;
        if (x != y) {
            adj[x].push_back({y, 0});
            adj[y].push_back({x, 1});
        }
	}

    cout << dijkstra(adj, 1);
	return 0;
}