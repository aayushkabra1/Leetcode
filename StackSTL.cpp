//
// Created by Aayush Kabra on 01-01-2022.
//
#include <iostream>
#include <stack>

using namespace std;

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    display(s);
    s.push(2);
    s.push(3);
    s.push(4);
    display(s);
    cout << endl;
    int x = s.top();
    cout << x << endl;
    s.pop();
    display(s);
    return 0;
}
