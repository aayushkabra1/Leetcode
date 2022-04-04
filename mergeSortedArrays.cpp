#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first = m - 1, second = n - 1, total = n + m - 1;
        while(first >= 0 && second >= 0) {
            if (nums1[first] > nums2[second]) nums1[total--] = nums1[first--];
            else nums1[total--] = nums2[second--];
        }

        while(second >= 0) {
            nums1[total--] = nums2[second--];
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    sol.merge(nums1, 0, nums2, 1);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}
