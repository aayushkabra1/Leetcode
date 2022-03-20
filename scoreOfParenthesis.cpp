#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                score++;
            }
        }
        return score;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.scoreOfParentheses("()()");
    return 0;
}
