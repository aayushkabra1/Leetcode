#include<iostream>
#include "bits/stdc++.h"
using namespace std;

template <class T>
class arithametic {

    private:
        T a, b;

    public:
        arithametic(T a, T b);
        T add();
        T sub();
};

template <class T>
arithametic<T>::arithametic(T a, T b) {
    this -> a = a;
    this -> b = b;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
