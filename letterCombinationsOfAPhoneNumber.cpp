#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, vector<char>> mapping;
        mapping['2'] = {'a', 'b', 'c'};
        mapping['3'] = {'d', 'e', 'f'};
        mapping['4'] = {'g', 'h', 'i'};
        mapping['5'] = {'j', 'k', 'l'};
        mapping['6'] = {'m', 'n', 'o'};
        mapping['7'] = {'p', 'q', 'r', 's'};
        mapping['8'] = {'t', 'u', 'v'};
        mapping['9'] = {'w', 'x', 'y', 'z'};

        vector<string> ans;
        for (char digit : digits) {
            
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string digits = "23";
    Solution s;
    vector<string> ans;
    ans = s.letterCombinations(digits);
    for (string s : ans) {
        cout << s << " "; 
    }
    cout << endl;
    return 0;
}



