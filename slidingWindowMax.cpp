#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<int> slidingMax1(vector<int> &nums, int k) {
    vector<int> ans;
    multiset<int, greater<int>> s(nums.begin(), nums.begin() + k);
    for (int i = 0; i < nums.size() - k + 1; i++) {
        ans.push_back(*s.begin());
        s.erase(nums[i]);
        s.insert(nums[i + k]);
    }
    return ans;
}

vector<int> slidingMax(vector<int> &nums, int k) {
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < k; i++) {
        while(!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    ans.push_back(nums[q.front()]);

    for (int i = k; i < nums.size(); i++) {
        cout << nums[q.front()] << " ";
        while(!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        while(!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = slidingMax(a, 3);
    return 0;
}

