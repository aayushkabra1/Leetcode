#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
            else {
                if (st.empty()) return false;
                char c = st.top();
                st.pop();
                if (s[i] == ')' && s[i] != '(') return false;
                if (s[i] == '}' && s[i] != '{') return false;
                if (s[i] == ']' && s[i] != '[') return false;
            }
        }
        return st.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.isValid("(]");
    return 0;
}
