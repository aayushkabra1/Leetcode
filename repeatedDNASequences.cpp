#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i = 0, n = s.size();
        unordered_map<string, int> mp;
        while(i + 10 <= n) {
            string temp = s.substr(i, 10);
            mp[temp]++;
            i++;
        }
        vector<string> ans;
        for (unordered_map<string, int>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
            if (itr->second > 1) ans.push_back(itr->first);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "AAAAAAAAAAA";
    vector<string> ans = sol.findRepeatedDnaSequences(s);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
