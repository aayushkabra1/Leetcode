#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     Solution() {
//         ios_base::sync_with_stdio(0);
//         cin.tie(NULL);
//     }

//     bool isPalindrome(vector<vector<int>> &palindromeTable, string &s, int i, int j) {
//         if (i == j) return (palindromeTable[i][j] = true);
//         if (j - i == 1) return (palindromeTable[i][j] = s[i] == s[j]);
//         if (palindromeTable[i][j] != -1) return palindromeTable[i][j];
//         if (s[i] == s[j]) return palindromeTable[i][j] = isPalindrome(palindromeTable, s, i + 1, j - 1);
//         return palindromeTable[i][j] = false;
//     }

//     int countSubstrings(string s) {
//         int n = s.size();
//         vector<vector<int>> palindromeTable(n, vector<int>(n, -1));
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 ans += isPalindrome(palindromeTable, s, i, j);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int left = i, right = i;
            ans++;
            while(left - 1 >= 0 && right + 1 < n && s[left - 1] == s[right + 1]) {
                ans++;
                left--;
                right++;
            }

            if (i > 0 && s[i - 1] == s[i]) {
                ans++;
                left = i - 1; right = i;
                while(left - 1 >= 0 && right + 1 < n && s[left - 1] == s[right + 1]) {
                    ans++;
                    left--;
                    right++;
                }
            }
        }
        return ans;
    }
};