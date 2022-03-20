#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
    int prev2 = nums[0];
    int prev1 = nums[1];
    int curr = nums[2];
    int i = 2;
    
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 1, 1, 2, 2, 3};
    int k = removeDuplicates(v);
    return 0;
}