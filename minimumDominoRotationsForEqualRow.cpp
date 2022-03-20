#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;
        int ans = 0;
        bool flag1 = true;
        bool flag2 = true;

        int temp1 = 0;
        for (int i : tops) freq1[i]++;
        int maxEl = freq1.begin()->first;
        int maxFreq = freq1.begin()->second;

        for (auto itr = freq1.begin(); itr != freq1.end(); itr++) {
            if (itr->second > maxFreq) {
                maxFreq = itr->second;
                maxEl = itr->first;
            }
        }

        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != maxEl) {
                if (bottoms[i] != maxEl) {
                    temp1 = 0;
                    flag1 = false;
                    break;
                }
                temp1++;
            }
        }
        

        for (int i : bottoms) freq2[i]++;
        maxEl = freq2.begin()->first;
        maxFreq = freq2.begin()->second;
        for (auto itr = freq2.begin(); itr != freq2.end(); itr++) {
            if (itr->second > maxFreq) {
                maxFreq = itr->second;
                maxEl = itr->first;
            }
        }

        int temp2 = 0;
        for (int i = 0; i < bottoms.size(); i++) {
            if (bottoms[i] != maxEl) {
                if (tops[i] != maxEl) {
                    temp2 = 0;
                    flag2 = false;
                    break;
                }
                temp2++;
            }
        }
        
        if (flag1 == false && flag2 == false) return -1;
        else if (flag1 == false) return temp2;
        else if (flag2 == false) return temp1;
        else return min(temp1, temp2);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> tops = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms = {5, 2, 6, 2, 3, 2};
    cout << s.minDominoRotations(tops, bottoms);
    return 0;
}
