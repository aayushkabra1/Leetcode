#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int h = accumulate(weights.begin(), weights.end(), 0);
        int l = max(h / days, *max_element(weights.begin(), weights.end()));
        
        
        while (l < h) {
            int mid = l + (h-l) / 2;
            
            if (helper(weights, mid, days)) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
    
    bool helper(vector<int>& weights, int cap, int days) {
        int count = 1;
        int cur = 0;
        
        for (auto &w: weights) {
            cur += w;
            if (cur > cap) {
                count ++;
                cur = w;
            } 
        }
        
        return count <= days;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> weights = {1,2,3,1,1};
    int days = 4;
    cout << sol.shipWithinDays(weights, days) << endl;
    return 0;
}
