#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0, ans = 0;
        char prev = '(';
        for (char c : s) {
            if (c == '(') depth++;
            else {
                depth--;
                if (prev == '(') {
                    ans += pow(2, depth);
                }
            }
            prev = c;
        }
        return ans;
    }   
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.scoreOfParentheses("(())");
    return 0;
}
