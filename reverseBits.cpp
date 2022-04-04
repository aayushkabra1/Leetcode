#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int  NO_OF_BITS = sizeof(n) * 8;
        unsigned int reverse_num = 0, i, temp;
  
        for (i = 0; i < NO_OF_BITS; i++) {
            temp = (n & (1 << i));
            if(temp)
                reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
        }
   
        return reverse_num;
    }
};