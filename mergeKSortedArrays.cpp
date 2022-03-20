#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        vector<int> indices(K, 0);
        priority_queue<pair<int, int>> pq;        // Value, Array_Number
        
        for (int i = 0; i < K; i++) {
            if (indices[i] < arr[i].size()) pq.push(make_pair(arr[i][indices[i]], i));
        }

        while(!pq.empty()) {
            pair<int, int> temp = pq.top();
            pq.pop();
            ans.push_back(temp.first);
            indices[temp.second] -= 1;
            if (indices[temp.second] < arr[temp.second].size()) {
                pair<int, int> tempPair = make_pair(arr[temp.second][indices[temp.second]], indices[temp.second]);
                pq.push(tempPair);
            }
        }
        return ans;
    }
};