#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &stalls, int dist, int C) {
    int lastStall = stalls[0];
    int cowsPlaces = 1;
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastStall >= dist) {
            cowsPlaces++;
            lastStall = stalls[i];
        }
        if (cowsPlaces >= C) return true;
    }
    return false;
}

int solve(vector<int> &stalls, int N, int C) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[N - 1] - stalls[0];
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if (check(stalls, mid, C)) {
            low = mid + 1;
            ans = mid;
        }
        else high = mid - 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int N, C;
        cin >> N >> C;
        vector<int> stalls(N);
        for (int i = 0; i < N; i++) {
            cin >> stalls[i];
        }

        cout << solve(stalls, N, C);
    }
    return 0;
}
