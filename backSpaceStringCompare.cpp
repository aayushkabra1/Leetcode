#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for (char c : s) {
            if (c == '#') {
                if (!st1.empty()) st1.pop();
            }
            else st1.push(c);
        }
        for (char c : t) {
            if (c == '#') {
                if (!st2.empty()) st2.pop();
            }
            else st2.push(c);
        }
        return st1 == st2;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "xywrrmp";
    string t = "xywrrmu#p";
    cout << sol.backspaceCompare(s, t);
    return 0;
}
