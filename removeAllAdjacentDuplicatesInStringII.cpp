#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;

        for (int i = 0; i < n; i++) {
            if (st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1});
            }
            else if (s[i] == st.top().first) {
                int count = st.top().second;
                st.pop();
                st.push({s[i], count + 1});
            }

            if (st.top().second == k) st.pop();
        }

        string ans = "";
        while(!st.empty()) {
            pair<char, int> temp = st.top(); st.pop();
            for (int i = 0; i < temp.second; i++) {
                ans.push_back(temp.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "pbbcggttciiippooaais";
    int k = 2;
    cout << sol.removeDuplicates(s, k);
    return 0;
}
