#include <vector>
#include <queue>
using namespace std;


// Naive Approach
// class KthLargest {
// public:
//     vector<int> vec;
//     int K;
//     KthLargest(int k, vector<int>& nums) {
//         sort(nums.begin(), nums.end(), greater<int>());
//         this->vec = nums;
//         this->K = k;
//     }
    
//     int add(int val) {
//         int i = 0;
//         while(i < this->vec.size() && this->vec[i] > val) {
//             i++;
//         }
//         vec.insert(vec.begin() + i, val);
//         return this->vec[this->K - 1];
//     }
// };

// Efficient Approach
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        this->K = k;
        for (int i : nums) {
            pq.push(i);
            if (pq.size() > K) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }
};