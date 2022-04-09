#include<unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        int n = s1.size();

        int front = 0;
        for (front; front < n; front++) {
            if (s2[front] != s1[front]) {
                break;
            }
        }
        
        int last = n - 1;
        for (last; last >= 0; last--) {
            if (s2[last] != s1[last]) {
                break;
            }
        }

        swap(s1[front], s1[last]);
        return s1 == s2;
    }
};