#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isEqual(unordered_map<char, int> &m1, unordered_map<char, int> &m2) {
        unordered_map<char, int>::iterator itr = m1.begin();
        for (; itr != m1.end(); itr++) {
            if (itr->second != m2[itr->first]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> pMap, sMap;
        for (char c : p) pMap[c]++;

        int np = p.size(), ns = s.size();
        int start = np - 1;
        for (int i = 0; i < np; i++) {
            sMap[s[i]]++;
        }

        while(start < ns - 1) {
            if (isEqual(sMap, pMap)) {
                ans.push_back(start - np + 1);
            }
            sMap[s[start + 1]]++;
            sMap[s[start - np + 1]]--;
            start++;
        }
        if (isEqual(sMap, pMap)) {
            ans.push_back(start - np + 1);
        }
        return ans;
    }
};