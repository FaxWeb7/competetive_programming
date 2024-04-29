#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;

class MinStack {
public:
    vector<int> stack;
    vector<int> mins;
    int size = 0;
    int minsSize = 0;
    
    MinStack() {
        stack.resize(3E4);
        mins.resize(3E4);
    }
    
    void push(int val) {
        stack[size++] = val;
        if (minsSize == 0 || val <= mins[minsSize-1]) {
            mins[minsSize++] = val;
        }
    }
    
    void pop() {
        size--;
        if (stack[size] == mins[minsSize-1]) minsSize--;
    }
    
    int top() {
        return stack[size-1];
    }
    
    int getMin() {
        return mins[minsSize-1];
    }
};

int main(){
    stack<int> s;

    return 0;
}