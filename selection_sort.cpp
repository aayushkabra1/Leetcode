#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = min_index; j < n; j++) {
            if (A[j] < A[min_index]) min_index = j;
        }
        swap(A[i], A[min_index]);
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {1, 3, 2, 5, 4, 7, 6, 9, 8};
    int size = sizeof(A) / sizeof(int);

    selection_sort(A, size);

    for (int x : A) cout << x << " ";
    cout << endl;
    return 0;
}
