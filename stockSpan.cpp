#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
        vector<int> ans(n, 1);
        stack<pair<int, int>> st;
        st.push(make_pair(price[0], 1));
        for (int i = 1; i < n; i++) {
            while(!st.empty() && st.top().first < price[i]) {
                ans[i] += st.top().second;
                st.pop();
            }
            st.push(make_pair(price[i], ans[i]));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
