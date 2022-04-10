#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> record;
        for (string s: ops) {
            if (s == "C") record.pop();
            else if (s == "D") record.push(record.top() * 2);
            else if (s == "+") {
                int temp = record.top(); record.pop();
                int sum = temp + record.top();
                record.push(temp);
                record.push(sum);
            }
            else {
                record.push(stoi(s));
            }
        }

        int ans = 0;
        while(!record.empty()) {
            ans += record.top();
            record.pop();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> ops = {"5","2","C","D","+"};
    cout << sol.calPoints(ops);
    return 0;
}
