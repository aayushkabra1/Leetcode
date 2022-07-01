#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), [] (vector<int> &a, vector<int> &b) {
            return a[1] > b[1];
        });
        
        int i = 0, n = boxTypes.size();
        
        while(truckSize > 0 && i < n) {
            int numberOfBoxes = min(boxTypes[i][0], truckSize);
            boxTypes[i][0] -= numberOfBoxes;
            int numberOfUnitsPerBox = boxTypes[i][1];
            
            ans += numberOfBoxes * numberOfUnitsPerBox;
            truckSize -= numberOfBoxes;
            if (boxTypes[i][0] == 0) i++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> box = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;
    cout << sol.maximumUnits(box, truckSize);
    return 0;
}
