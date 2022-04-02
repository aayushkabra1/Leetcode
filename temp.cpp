#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    map<int, int> mp;
    mp[1]++;
    mp[2]--;
    mp.erase(1);
    cout << mp.empty();
    cout << mp[2];
    return 0;
}

