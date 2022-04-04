#include  <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<uint32_t, int> mp;
    int hammingWeight(uint32_t n) {
        if (mp.find(n) != mp.end()) return mp[n]; 
        return mp[n] = __builtin_popcount(n);
    }
};