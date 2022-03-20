#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        vector<int> window(K, 0);
        int ans = 0;
        for (int i = 0; i < K; i++) {
            window[i] = Arr[i];
            ans += Arr[i];
        }
        
        int sum = ans;
        for (int i = K; i < N; i++) {
            sum -= *window.begin();
            window.erase(window.begin());
            sum += Arr[i];
            window.push_back(Arr[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};