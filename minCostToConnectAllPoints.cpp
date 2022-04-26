#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;

class Solution {
public:
    int manhattan(vector<int> &v1, vector<int> &v2) {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }

    int parent(vector<int> &parents, int i) {
        if (parents[i] == i) return i;
        return parents[i] = parent(parents, parents[parents[i]]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> parents(n);
        int ans = 0, numOfEdges = 0;
        iota(parents.begin(), parents.end(), 0);

        priority_queue<vector<int>> pq; // weight, <src, dest>
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pq.push({-1 * manhattan(points[i], points[j]), i, j});
            }
        }

        while(numOfEdges != n - 1) {
            vector<int> temp = pq.top(); pq.pop();
            int parent1 = parent(parents, temp[1]);
            int parent2 = parent(parents, temp[2]);

            if (parent1 == parent2) continue;
            ans -= temp[0]; parents[parent1] = parent2; numOfEdges++;
        }

        return ans;
    }
};