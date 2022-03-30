#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

// Approach 1
class Solution {
public:
    int decToBinary(int n) {
        int count = 0;
        int binaryNum[32];
        int i = 0;
        while (n > 0) {
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            count += (binaryNum[j] == 1);
        }

        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            ans[i] = decToBinary(i);
        }
        return ans;
    }
};

// Approach 2
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans(n + 1, 0);
//         for (int i = 0; i <= n; i++) {
//             ans[i] = __builtin_popcount(i);
//         } 
//         return ans;
//     }
// };
