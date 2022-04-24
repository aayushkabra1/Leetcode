#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class UndergroundSystem {
    unordered_map<int, pair<string, int>> checkInMap;       // <id, <station, time>>
    map<pair<string, string>, pair<int, int>> time;         // <<start, end>, <total time, total passenger>>

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string checkInStation = checkInMap[id].first;
        int checkInTime = checkInMap[id].second;
        time[make_pair(checkInStation, stationName)].first += t - checkInTime;
        time[make_pair(checkInStation, stationName)].second++; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        return ((double)time[make_pair(startStation, endStation)].first) / time[make_pair(startStation, endStation)].second;
    }
};