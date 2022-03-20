#include<iostream>
#include<stdlib.h>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

void area(rectangle r){
    cout<<"Area of rectangle is "<<r.length*r.breadth<<endl;
}

void init(rectangle *r, int l, int b) {
    r -> length = l;
    r -> breadth = b;
}
 
void changeLength(rectangle *r, int l) {
    r -> length = l;
}

int main(int argc, char const *argv[]) {

    rectangle r;
    init(&r, 10, 20);
    area(r);
    changeLength(&r, 5);
    return 0;
}

