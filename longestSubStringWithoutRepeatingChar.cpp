#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hasOccured(256, -1);
        int maxLength = 0;
        int i = -1;
        for (int j = 0; j < s.length(); j++) {
            if(hasOccured[s[j]] > i) {
                i = hasOccured[s[j]];
            }
            hasOccured[s[j]] = j;
            maxLength = max(maxLength, j - i);
        }
        return maxLength;
    }
};

int main(int argc, char const *argv[])
{
    string s = "pwwkew";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}

