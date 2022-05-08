#include <iostream>
#include <vector>
using namespace std;

class NestedInteger {
    public:
        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const;

        //Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const;

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    vector<int> vec;
    int index = 0;

    void util(vector<NestedInteger> &nestedList) {
        for (auto i : nestedList) {
            if (i.isInteger()) vec.push_back(i.getInteger());
            else util(i.getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        util(nestedList);
    }
    
    int next() {
        return vec[index++];
    }
    
    bool hasNext() {
        return index < vec.size();
    }
};