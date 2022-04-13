#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int sr = 0, sc = 0;
        int er = n - 1, ec = n - 1;
        int number = 1;
        while(sr <= er && sc <= ec) {
            for (int i = sc; i <= ec; i++) {
                ans[sr][i] = number++;
            }
            sr++;

            for (int i = sr; i <= er; i++) {
                ans[i][ec] = number++;
            }
            ec--;

            if (sr <= er) {
                for (int i = ec; i >= sc; i--) {
                    ans[er][i] = number++;
                }
                er--;
            }

            if (sc <= ec) {
                for (int i = er; i >= sr; i--) {
                    ans[i][sc] = number++;
                }
                sc++;
            }
        }
        return ans;
    }
};