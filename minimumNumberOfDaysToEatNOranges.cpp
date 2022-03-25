#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

unordered_map<int, int> mp;
class Solution {
public:

    int minDays(int n) {
       if (n < 2) return n;
       if (mp.count(n)) return mp[n];
       return mp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.minDays(14060463);
    return 0;
}
