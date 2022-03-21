#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }

        int start = 0;
        while(start < s.size()) {
            int lastIndex = mp[s[start]];
            for (int j = start + 1; j < lastIndex; j++) {
                if (mp[s[j]] > lastIndex) lastIndex = mp[s[j]];
            }
            ans.push_back(lastIndex - start + 1);
            start = lastIndex + 1;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
