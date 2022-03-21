#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, long long> freq, sumOfIndices;
        vector<long long> intervals(n);
        unordered_map<int, int> prev; 

        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
            sumOfIndices[arr[i]] += i;
        }

        for (int i = 0; i < n; i++) {
            sumOfIndices[arr[i]] -= (i - prev[arr[i]]) * freq[arr[i]];
            freq[arr[i]] -= 2;
            intervals[i] = sumOfIndices[arr[i]];
            prev[arr[i]] = i;
        }

        return intervals;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> arr = {2,1,3,1,2,3,3};
    vector<long long> ans = sol.getDistances(arr);
    for (long long i : ans) cout << i << " ";
    cout << "\n";
    return 0;
}
