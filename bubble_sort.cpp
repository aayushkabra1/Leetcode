#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

int main(int argc, char const *argv[]) {
    int a[] = {1, 3, 2, 5, 4, 7, 10, 6};
    int size = sizeof(a) / sizeof(int);

    bubble_sort(a, size);
    
    for (int x : a) std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
