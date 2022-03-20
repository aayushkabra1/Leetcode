#include<iostream>
using namespace std;

int search(int* A, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (A[i] == key) {
            return i;
        }
    }
    return -1;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {

    int A[] = {1, 2, 3, 2351, 3, 124, 12};
    cout << search(A, 7, 2351) << endl;
    for (int i = 0; i < 7; i++) {
        cout << A[i] << endl;
    }
    return 0;
}