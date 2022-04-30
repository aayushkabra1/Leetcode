#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = n - 1, mid;
        while(end >= start) {
            mid = (end - start) / 2 + start;
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) return mid;
            else if (arr[mid] < arr[mid + 1]) start = mid + 1;
            else if (arr[mid] < arr[mid - 1]) end = mid - 1;
        }
        return -1;
    }
};