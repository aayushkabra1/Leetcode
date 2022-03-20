#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    void split(string &s, stack<string> &st) {
        char del = '/';
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '/') continue;
            string temp = "";
            while (i < s.size() && s[i] != '/')
            {
                temp += s[i];
                i++;
            }
            if (temp == ".") continue;
            else if (temp == "..") {
                if (!st.empty()) st.pop();
            }
            else {
                st.push(temp);
            }
        }
    }

    string simplifyPath(string path) {
        string ans = "";
        stack<string> st;
        split(path, st);
        
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if (ans == "") ans += "/";
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string path = "/a/b/..";
    string ans = s.simplifyPath(path);
    cout << ans << endl;
    return 0;
}
