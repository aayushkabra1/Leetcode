//
// Created by Aayush Kabra on 01-01-2022.
//
#include <iostream>
#include <string>]
#include <stack>
using namespace std;

int main() {
    string s;
    cout << "Enter a string:  ";
    cin >> s;
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                cout << "Unbalanced" << endl;
                return 0;
            } else {
                if ((ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[')) {
                    st.pop();
                }else {
                    cout << "Unbalanced" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Balanced";
    return 0;
}