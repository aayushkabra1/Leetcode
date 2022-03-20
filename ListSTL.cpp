//
// Created by Aayush Kabra on 31-12-2021.
//
#include<iostream>
#include<list>

using namespace std;

void display(list<int> l)
{
    for(auto i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    list<int> l = list<int>(2);
    cout << l.size() << endl;
    auto itr = l.begin();
    return 0;
}
