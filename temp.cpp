#include "bits/stdc++.h"
using namespace std;

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        long long sum = (n + 1) * (n) / 2;
        for (int i = 0; i < n; i++)
            sum -= array[i];
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> arr = {2, 3, 4, 1, 6, 7};
    cout << sol.MissingNumber(arr, 7);
    return 0;
}

