#include <vector>
#include <unordered_map>
using namespace std;

class MyHashMap {
    unordered_map<int, int> mp;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) return mp[key];
        return -1;
    }
    
    void remove(int key) {
        mp.erase(key);
    }
};