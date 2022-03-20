#include <iostream>
using namespace std;

void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        int x = A[i];
        while(j > 0 && A[j - 1] > x) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = x;
    }
}

int main(int argc, char const *argv[])
{
    int A[]  = {1, 3, 2, 5, 4, 7, 6, 25, 20};
    int size = sizeof(A) / sizeof(int);

    insertion_sort(A, size);

    for (int x : A) cout << x << " ";
    cout << endl;
    return 0;
}
