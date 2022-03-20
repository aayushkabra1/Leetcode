#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0;
        x = abs(x);
        string numString = to_string(x);
        for (int i = 0; i < numString.length()/2; i++) {
            swap(numString[i], numString[numString.length() - i - 1]);
        }
        int32_t ans = stoi(numString);
        ans = ans * pow(-1, isNegative);
        if (ans < -1*pow(2, 31) || ans > pow(2, 32) - 1) return 0;
        return ans;
    }
};