#include <iostream>
using namespace std;

class Solution {
public:
    
    int gcd(int a, int b) {
        if (a < b) swap(a, b);
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        int gc = gcd(jug1Capacity, jug2Capacity);
        return (targetCapacity % gc == 0);
    }
};