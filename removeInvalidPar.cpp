#include <iostream>
#include <stack>
#define mp make_pair
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] == '(') st.push(mp(s[i], i));
            else if (s[i] == ')') {
                if (st.empty()) st.push(mp(s[i], i));
                else if (st.top().first == '(') st.pop();
                else st.push(mp(s[i], i));
            }
        }
        while(!st.empty()) {
            pair<char, int> temp = st.top();
            st.pop();
            s.erase(s.begin() + temp.second);
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.minRemoveToMakeValid("))((");
    return 0;
}
