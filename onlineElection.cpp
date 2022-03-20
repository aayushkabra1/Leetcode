#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TopVotedCandidate {
public:

    map<int, int> votes;           // <person, votes>
    map<int, int> leading;      // <time, person>
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        for (int i = 0; i < persons.size(); i++) {
            votes[persons[i]]++;
            int leadingPerson = votes.rbegin()->first;
            leading[times[i]] = leadingPerson;  
        }
    }
    
    int q(int t) {
        int i = 0;
        while(i < times.size() && i <= t) {
            i++;
        }
        return leading[times[i - 1]];
    }
};

