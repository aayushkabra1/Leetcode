#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

class returnType{
    public:
    std::vector<int> a;
    int count;

    returnType(std::vector<int> b, int c) {
        this->a = b;
        this->count = c;
    }
};

returnType countInversions(std::vector<int> &a){

    if (a.size() <= 1) return returnType(a, 0);

    int sum = 0;
    std::vector<int> leftVector(a.begin(), a.begin() + a.size()/2);
    std::vector<int> rightVector(a.begin() + a.size()/2, a.end());

    returnType left = countInversions(leftVector);
    returnType right = countInversions(rightVector);

    sum += left.count;
    sum += right.count;

    int i = 0, j = 0, k = 0;
    while(i < leftVector.size() && j < rightVector.size()) {
        if (leftVector[i] <= rightVector[j]) {
            a[k] = leftVector[i];
            i++;
        } else {
            a[k] = rightVector[j];
            j++;
            sum += leftVector.size() - i;
        }
        k++;
    }

    while(i < leftVector.size()) {
        a[k] = leftVector[i];
        i++;
        k++;
    }

    while(j < rightVector.size()) {
        a[k] = rightVector[j];
        j++;
        k++;
    }

    returnType obj(a, sum);
    return obj;
}

int main(int argc, char const **argv)
{

    std::vector<int> a(100000, 0);
    std::ifstream file("IntegerArray.txt");
    
    std::string num;
    for (int i = 0; i < 100000; i++) {
        getline(file, num);
        a[i] = std::stoi(num);
    }

    returnType Obj = countInversions(a);
    std::cout << Obj.count << std::endl;
    return 0;
}
