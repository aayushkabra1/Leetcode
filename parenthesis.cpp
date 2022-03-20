#include <iostream>
#include <stack>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        
        for (char c : x) {
            if (c == '{' || c == '[' ||c == '(') {
                st.push(c);
            }
            else {
                if (st.empty()) return false;
                if (c == '}' && st.top() == '{') st.pop();
                else if (c == ']' && st.top() == '[') st.pop();
                else if (c == ')' && st.top() == '(') st.pop();
                else return false;
            }
        }
        return st.empty();
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    bool ans = s.ispar("{([])}");
    cout << ans << endl;
    return 0;
}
