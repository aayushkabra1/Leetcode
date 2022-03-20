#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        if (s == t) return true;

        unordered_map<int, int> mp;
        for (int i = 0; i < s.size(); i++) {
            int diff = (t[i] >= s[i]) ? (t[i] - s[i]) : (26 - s[i] + t[i]);
            if (diff == 0) continue;
            mp[diff]++;
        }
        
        for (unordered_map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
            int first = itr->first;
            int freq = itr->second;
            int temp = first + (freq - 1)*26;
            if (temp > k) return false;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "input";
    string t = "ouput";

    cout << sol.canConvertString(s, t, 9);
    return 0;
}
