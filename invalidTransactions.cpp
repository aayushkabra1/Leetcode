#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<string> getNameTimeAmountCity(string s) {
        vector<string> ans;
        string delimiter = ",";
        size_t pos = 0;
        string token;

        while((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            ans.push_back(token);
            s.erase(0, s.find(delimiter) + delimiter.length());
        }
        ans.push_back(s);
        return ans;
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;

        
    }
};

