#include <iostream>
#include<string>

using namespace std;

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int m = INT_MIN;
    cout << m << endl;
    string s = "python";
    for(int i = 0; i < s.length() / 2; i++) {
        swap(&s[i], &s[s.length() - i - 1]);
    }
    cout << s << endl;
}