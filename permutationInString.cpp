#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < n1; i++) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if (m1 == m2) return true;
        for (int i = n1; i < n2; i++) {
            m2[s2[i]]++;
            m2[s2[i - n1]]--;
            if (m2[s2[i - n1]] == 0) m2.erase(s2[i - n1]);
            if (m1 == m2) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s1 = "ab", s2 = "eidbaooo";
    cout << sol.checkInclusion(s1, s2);
    return 0;
}
