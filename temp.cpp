#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    string a = "b";
    string b = "a";
    int diff = (b[0] > a[0]) ? (b[0] - a[0]) : (26 + a[0] - b[0]);
    cout << diff << endl;
    return 0;
}

