#include<iostream>
using namespace std;


int* fun(int n) {
    int *p = (int *)malloc(n * sizeof(int));
    *p = 1;
    return p;
}

int main() {

    int *p = fun(5);
    cout << *p << endl;
}