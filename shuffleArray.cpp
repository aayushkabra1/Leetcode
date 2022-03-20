#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> original;
    vector<int> arr;
    Solution(vector<int>& nums) {
        this->original = nums;
        this->arr = nums;
    }
    
    vector<int> reset() {
        return arr = original;
    }
    
    vector<int> shuffle() {
        for (int i = arr.size() - 1; i > 0; i--) {
            int randomNum = rand() % (i + 1);
            swap(arr[i], arr[randomNum]);
        }
        return this->arr;
    }
};
