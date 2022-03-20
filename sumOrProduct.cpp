#include <iostream>
#include <cmath>
using namespace std;

long long int sumOrProduct(long long int n, long long int q)
{
	// Write your code here.
    if (q == 1) {
        return (long long)n * (n + 1) / 2;
    }
   long long prod = 1;
    for (int i = 2; i <= n; i++) {
        prod = prod * i;
    }
    return prod % (long long)(pow(10, 9) + 7);
}

int main(int argc, char const *argv[])
{
    cout << sumOrProduct(23, 2) << endl;
    return 0;
}
