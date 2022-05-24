#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indexSt;
        int n = s.size();
        int ans = 0;
        indexSt.push(-1);
        for (int i  = 0; i < n; i++) {
            if (s[i] == ')' && indexSt.top() != -1 && s[indexSt.top()] == '(') {
                indexSt.pop();
                ans = max(ans, i - indexSt.top());
            }
            else {
                indexSt.push(i);
            }
        }
        return ans;
    }
};