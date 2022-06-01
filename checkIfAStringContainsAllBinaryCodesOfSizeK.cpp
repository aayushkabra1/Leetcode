#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size(), total = pow(2, k);
        if (n <= k) return false;
        unordered_map<string, int> mp;
        string subString = "";
        for (int i = 0; i < k; i++) {
            subString.push_back(s[i]);
        }
        mp[subString]++;
        for (int i = k; i < n; i++) {
            subString.erase(0, 1);
            subString.push_back(s[i]);
            mp[subString]++;
            if (mp.size() == total) return 1;
        }
        
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "00110110";
    int k = 2;
    cout << sol.hasAllCodes(s, k);
    return 0;
}
