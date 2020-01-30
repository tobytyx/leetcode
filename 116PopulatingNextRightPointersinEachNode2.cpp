# include <iostream>
# include <queue>
# include <vector>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(): val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val): val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next): val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL){
            return root;
        }
        queue<Node*> q;
        Node* cur = NULL;
        Node* last = NULL;
        Node* pre = NULL;
        q.push(root);
        while (not q.empty()){
            last = q.back();
            pre = NULL;
            while(cur != last){
                cur = q.front();
                q.pop();
                if (pre != NULL){
                    pre->next = cur;
                }
                pre = cur;
                if (cur->left != NULL){
                    q.push(cur->left);
                }
                if (cur->right != NULL){
                    q.push(cur->right);
                }
            }
        }
        return root;
    }
};


int main(){
    Solution s;
    return 0;
}
