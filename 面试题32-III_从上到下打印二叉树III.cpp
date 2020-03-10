#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        deque<TreeNode*> q(1, root);
        bool reverse = false;
        while(!q.empty()){
            int len = q.size();
            deque<int> cache;
            for(int i=0; i<len; i++){
                TreeNode *cur = q.back();
                q.pop_back();
                if(reverse)
                    cache.push_front(cur->val);
                else
                    cache.push_back(cur->val);
                if(cur->left != NULL) q.push_front(cur->left);
                if(cur->right != NULL) q.push_front(cur->right);
            }
            res.push_back(vector<int>(cache.begin(), cache.end()));
            reverse = !reverse;
        }
        return res;
    }
};

int main(){
    deque<int> a;
    a.push_front(1);
    a.push_front(2);
    a.push_front(3);
    vector<int> b(a.begin(), a.end());
    for(int i: b) printf("%d ", i);
    printf("\n");
    return 0;
}
