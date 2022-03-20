#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {

    int leftArraySize = m - l + 1, rightArraySize = r - m;

    int leftArray[leftArraySize], rightArray[rightArraySize];

    for(int i = 0; i < leftArraySize; i++) {
        leftArray[i] = arr[l + i];
    }

    for(int i = 0; i < rightArraySize; i++) {
        rightArray[i] = arr[m + 1 + i];
    }
    
    int i = 0, j = 0, k = l;

    while (i < leftArraySize && j < rightArraySize) {
        if (leftArray[i] < rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftArraySize) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightArraySize) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {

    int m = (l + r) / 2;

    if (l < r) {
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m,  r);
    }
}


int main() {

    int arr[100];
    int n;
    cout << "Enter the size of the array (< 100): ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Enter the element " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    mergeSort(arr, 0, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}