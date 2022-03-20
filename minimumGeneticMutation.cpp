#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:

    void generateMutations(string s, vector<char> &mutations, map<string, vector<string>> &adj) {
        vector<string> temp;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < mutations.size(); j++) {
                temp.push_back(s.substr(0, i) + mutations[j] + s.substr(i + 1));
            }
        }
        adj[s] = temp;
        temp.clear();
    }

    int minMutation(string start, string end, vector<string>& bank) {
        map<string, vector<string>> adj;
        map<string, int> visited;
        vector<char> mutations = {'A', 'T', 'C', 'G'};

        queue<string> q;
        int level = 0;
        q.push(start);
        q.push(" ");

        while(!q.empty()) {
            string s = q.front();
            q.pop();
            
            if (s == end) return level;
            if (s != " ") {
                generateMutations(s, mutations, adj);
                for (string temp : adj[s]) {
                    if (find(bank.begin(), bank.end(), temp) != bank.end() && !visited[temp])  {
                        q.push(temp);
                        visited[temp]++;
                    }
                }
            }
            else {
                if (!q.empty()) {
                    level++;
                    q.push(" ");
                }
            }
        }
        return -1;
    }
};