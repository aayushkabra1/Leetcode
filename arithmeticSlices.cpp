#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size(), prev=2 ,res=0;
        for(int i=2;i<n;i++){
            int first =  nums[i-1]-nums[i-2];
            int second=  nums[i]-nums[i-1];
            first==second? prev++ : prev=2;
            if(prev>=3) res+= (prev-2); 
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << sol.numberOfArithmeticSlices(nums);
    return 0;
}
