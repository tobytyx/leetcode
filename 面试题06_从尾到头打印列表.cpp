#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        deque<int> q;
        while(head != NULL){
            q.push_front(head->val);
            head = head->next;
        }
        vector<int> res(q.begin(), q.end());
        return res;
    }
};

int main(){
    Solution s;
    string str = "123 retrt ";
    
    return 0;
}
