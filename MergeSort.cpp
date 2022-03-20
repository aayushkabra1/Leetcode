#include <iostream>

void merge(int A[], int l, int m, int r) {
    int leftArraySize = m - l + 1;
    int rightArraySize = r - m;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++) {
        leftArray[i] = A[l + i];
    }

    for (int j = 0; j < rightArraySize; j++) {
        rightArray[j] = A[m + 1 + j];
    }

    int indexOfLeft = 0, indexOfRight = 0, k = l;
    while(indexOfLeft < leftArraySize && indexOfRight < rightArraySize) {
        if (leftArray[indexOfLeft] > rightArray[indexOfRight]) {
            A[k] = rightArray[indexOfRight];
            indexOfRight++;
        } else {
            A[k] = leftArray[indexOfLeft];
            indexOfLeft++;
        }
        k++;
    }

    while(indexOfLeft < leftArraySize) {
        A[k] = leftArray[indexOfLeft];
        indexOfLeft++;
        k++;
    }
    while(indexOfRight < rightArraySize) {
        A[k] = rightArray[indexOfRight];
        indexOfRight++;
        k++;
    }
}

void mergeSort(int A[], int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    mergeSort(A, 0, m);
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    int arr[] =  {1, 3, 2, 5, 4, 7, 6, 9, 8, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    mergeSort(arr, 0, size);
    printArray(arr, size);
    return 0;
}
