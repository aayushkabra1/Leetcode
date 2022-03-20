#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>> maxHeap;

public:
    
    MedianFinder() {
        minHeap;
        maxHeap;
    }
    
    void addNum(int num) {
        if (minHeap.size() == maxHeap.size()) {
            if (maxHeap.size() == 0) maxHeap.push(num);
            else {
                if (num <= maxHeap.top()) maxHeap.push(num);
                else minHeap.push(num);
            }
        } else {
            if (maxHeap.size() > minHeap.size()) {
                if (num > maxHeap.top()) minHeap.push(num);
                else {
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(temp);
                    maxHeap.push(num);
                }
            } else {
                if (num < minHeap.top()) maxHeap.push(num);
                else {
                    int temp = minHeap.top();
                    minHeap.pop();
                    minHeap.push(num);
                    maxHeap.push(temp);
                }
            }
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        else if (minHeap.size() > maxHeap.size()) return minHeap.top();
        else return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};