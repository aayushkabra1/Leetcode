#include "bits/stdc++.h"
using namespace std;


int main(int argc, char const *argv[])
{
    unordered_map<int, int> mp1, mp2;
    mp1[1] = 1;
    mp2[1] = 1;
    cout << (mp1 == mp2);
    return 0;
}

