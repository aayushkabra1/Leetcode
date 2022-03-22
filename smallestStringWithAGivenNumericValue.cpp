#include <iostream>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int index = n - 1;
        k -= n;
        while(k > 0) {
            int temp = min('z' - ans[index], k);
            k -= temp;
            ans[index] = (char) (ans[index] + temp);
            if (ans[index] == 'z') index--;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 5;
    int k = 73;
    cout << sol.getSmallestString(n, k) << "\n";
    return 0;
}
