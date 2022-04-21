#include  <iostream>
#include <unordered_map>
using namespace std;

class MyHashSet {
    unordered_map<int, int> mp;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        mp[key] = 0;
    }
    
    void remove(int key) {
        mp.erase(key);
    }
    
    bool contains(int key) {
        return mp.find(key) != mp.end();
    }
};