#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if (st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }   
        }
        int temp = st2.top();
        st2.pop();
        return temp;        
    }
    
    int peek() {
        if (st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }     
        }
        return st2.top(); 
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int main(int argc, char const *argv[])
{
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    return 0;
}
