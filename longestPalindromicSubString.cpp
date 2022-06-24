#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        
        int maxLen = 1, start = 0;
        for (int i = 0; i < n; i++) {
            int low = i - 1, high = i + 1;
            while(high < n && s[i] == s[high]) high++;
            while(low >= 0 && s[i] == s[low]) low--;
            while(low >= 0 && high < n && s[high] == s[low]) {
                low--; high++;
            }
            
            if (high - low - 1 > maxLen) {
                maxLen = high - low - 1;
                start = low + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "cbbd";
    cout << sol.longestPalindrome(s);
    return 0;
}
