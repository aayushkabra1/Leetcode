//
// Created by Aayush Kabra on 01-01-2022.
//
#include<iostream>
#include<stack>
using namespace std;

int main() {

    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    stack<char> s;
    for (char c : infix) {
        if (isalpha(c)) {cout << c;}

        else if(c == '*' || c == '/') {
            while(!s.empty() && (s.top() == '*' || s.top() == '/')) {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }

        else if (c == '+' || c == '-') {
            while(!s.empty()) {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    return 0;
}