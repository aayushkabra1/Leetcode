#include <iostream>
#include <stack>
#include <map>
using namespace std;

class FreqStack {
public:

    map<int, int> elToFreq;
    map<int, stack<int>> freqToEl;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        int freq = elToFreq[val] + 1;
        elToFreq[val] = freq;

        if (freq > maxFreq) maxFreq = freq;
        freqToEl[freq].push(val);
    }
    
    int pop() {
        int el = freqToEl[maxFreq].top();
        freqToEl[maxFreq].pop();
        elToFreq[el]--;
        
        if (freqToEl[maxFreq].empty()) {
            maxFreq--;
        }
        return el;
    }
};
