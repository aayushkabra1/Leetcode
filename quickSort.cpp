#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void printArray(const vector<int> &A) { 
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    } 
    cout << endl;
}

int partition(vector<int> A, int l, int r) {
    int pivotElement = A[l];
    int i = l + 1;

    for (int j = 0; j < r; j++) {
        if (A[j] < pivotElement) {
          swap(A[i], A[j]);
          i++;
        }
    }
    swap(A[l], A[i-1]);   
    return i; 
}

void quickSort(vector<int> &A, int start, int end) {
    if (start >= end) return;
    int pi = partition(A, 0, A.size());
    quickSort(A, start, pi - 1);
    quickSort(A, pi + 1, end);
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 3, 2, 5, 4, 7, 6, 9, 8};
    printArray(A);
    quickSort(A, 0, A.size());
    printArray(A);
    return 0;
}

