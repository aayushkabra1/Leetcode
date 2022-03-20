#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() <= 2) return true;
        int first = 0;
        int second = 0;
        stack<int> st;
        
        for (first; first < pushed.size(); first++) {
            st.push(pushed[first]);
            while(!st.empty() && st.top() == popped[second]) {
                st.pop(); second++;
            }
        }
        return st.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> pushed = {0, 2, 1};
    vector<int> popped = {0, 1, 2};
    cout << s.validateStackSequences(pushed, popped);
    return 0;
}
