#include <iostream>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() == sentence2.size()) return sentence1 == sentence2;
        if (sentence1.size() < sentence2.size()) swap(sentence1, sentence2);

        int front = 0;
        int last1 = sentence1.size() - 1;
        int last2 = sentence2.size() - 1;

        while(front < sentence2.size()) {
            if (sentence1[front] == sentence2[front]) front++;
            else break;
        }
        
        while(last1 >= 0 && last2 >= 0) {
            if (sentence1[last1] == sentence2[last2]) {
                last1--;
                last2--;
            }
            else break;
        }


};

int main(int argc, char const *argv[])
{
    Solution s;
    bool ans = s.areSentencesSimilar("My name is Haley", "My Haley"); 
    cout << ans << endl;
    return 0;
}
