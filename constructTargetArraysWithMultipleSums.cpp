#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<int> pq;
        long long sum = 0;
        
        for (int num : target) {
            pq.push(num);
            sum += num;
        }
        
        while(pq.top() != 1) {
            sum -= pq.top();
            if (sum >= pq.top() || sum == 0) return false;
            int lastEl = pq.top() % sum;
            
            if (sum != 1 && lastEl == 0) return false;
            pq.pop();
            pq.push(lastEl);
            sum += lastEl;
        }
        
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> target = {1,1000000000};
    cout << sol.isPossible(target);
    return 0;
}
