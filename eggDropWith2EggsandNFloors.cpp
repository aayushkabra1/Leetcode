#include <iostream>
using namespace std;

int fast = [] () {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int twoEggDrop(int n) {
        int i = n, ans = 0;
        while(i > 0) {
            ans++;
            i -= ans;
        }
        return ans;
    }
};