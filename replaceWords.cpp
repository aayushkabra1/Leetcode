#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:

    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        string word;
        sort(dictionary.begin(), dictionary.end());
        istringstream iss(sentence);

        while(iss >> word) {
            bool rootPresent = false;
            for (int i = 0; i < word.length(); i++) {
                string temp = word.substr(0, i + 1);
                if (binary_search(dictionary.begin(), dictionary.end(), temp)) {
                    ans = ans + temp + " ";
                    rootPresent = true;
                    break;
                }
            }
            if (!rootPresent) ans = ans + word + " ";
        }
        ans.pop_back();
        return ans;
    }
};