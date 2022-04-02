#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        while(end < n) {
            if (s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
            end++;
        }
        reverse(s.begin() + start, s.begin() + end);
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "Let's take LeetCode contest";
    cout << sol.reverseWords(s);
    return 0;
}
