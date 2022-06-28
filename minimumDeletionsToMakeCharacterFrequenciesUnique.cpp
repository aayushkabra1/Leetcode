#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        for (int i = 1; i < 26; i++) {
            if (freq[i] == 0) break;
            
            if (freq[i] >= freq[i - 1]) {
                int temp = freq[i];
                freq[i] = max(0, freq[i - 1] -1);
                ans += temp - freq[i];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "ceabaacb";
    cout << sol.minDeletions(s);
    return 0;
}
