#include <iostream>
using namespace std;

int guess(int i) {
    // api given
}

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        int mid;
        
        while(end >= start) {
            mid = start + (end - start) / 2;
            int  g = guess(mid);
            if (g == -1) end = mid - 1;
            else if (g == 1) start = mid + 1;
            else if (g == 0) return mid;
        }
        return -1;
    }
};