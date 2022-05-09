#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        deque<string> q;
        for (char c : mp[digits[0]]) {
            string s; s.push_back(c);
            q.push_back(s);
        }
        for (int i = 1; i < n; i++) {
            int size = q.size();
            while(size--) {
                string temp = q.front(); q.pop_front();
                for (int j = 0; j < mp[digits[i]].size(); j++) {
                    q.push_back(temp + mp[digits[i]][j]);
                }
            }
        }
        return vector<string>({q.begin(), q.end()});
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



