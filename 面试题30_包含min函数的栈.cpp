#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> minstack;
    MinStack() {

    }
    
    void push(int x) {
        stack.push_back(x);
        if(minstack.empty()) minstack.push_back(x);
        else{
            if(x < minstack.back()) minstack.push_back(x);
            else minstack.push_back(minstack.back());
        }
    }
    
    void pop() {
        if(!stack.empty()) stack.pop_back();
        if(!minstack.empty()) minstack.pop_back();
    }
    
    int top() {
        if(stack.empty()) return -1;
        return stack.back();
    }
    
    int min() {
        if(minstack.empty()) return -1;
        return minstack.back();
    }
};