#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int it = 0, is = 0;
        if (s.size() == 0) return true;
        for (it = 0; it < t.size(); it++) {
            if (s[is] == t[it]) {
                is++;
            }
            if (is == s.size()) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "abc", t = "ahbgdc";
    cout << sol.isSubsequence(s, t);
    return 0;
}


