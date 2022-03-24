#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int left = 0;
        int right = n - 1;
        int numOfBoats = 0;
        std::sort(people.begin(), people.end());

        while(left < right) {
            left += (people[left] + people[right] <= limit);
            numOfBoats++;
            right--;
        }
        numOfBoats += (left == right);
        return numOfBoats;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> people = {3,5,3,4};
    int limit = 5;
    std::cout << sol.numRescueBoats(people, limit) << "\n";
    return 0;
}
