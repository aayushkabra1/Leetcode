#include <iostream>
#include <unordered_set>

int main(int argc, char const *argv[])
{
    std::unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);

    std::unordered_set<int> t;
    t.insert(4);
    t.insert(3);

    

    return 0;
}
