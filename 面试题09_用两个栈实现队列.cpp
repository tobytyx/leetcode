#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class CQueue {
public:
    vector<int> stack1;
    vector<int> stack2;

    CQueue() {
    }
    
    void appendTail(int value) {
        stack1.push_back(value);
    }
    
    int deleteHead() {
        if(stack1.empty()) return -1;
        while(!stack1.empty()){
            stack2.push_back(stack1.back());
            stack1.pop_back();
        }
        int val = stack2.back();
        stack2.pop_back();
        while(!stack2.empty()){
            stack1.push_back(stack2.back());
            stack2.pop_back();
        }
        return val;
    }
};

int main(){

    return 0;
}
