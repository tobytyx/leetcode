# include <iostream>
# include <queue>
# include <vector>
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
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        TreeNode* last = root;
        int level = 0;
        q.push(root);
        res.push_back(vector<int>());
        while(not q.empty()){
            TreeNode* q1 = q.front();
            q.pop();
            res[level].push_back(q1->val);
            if(q1->left)
                q.push(q1->left);
            if(q1->right)
                q.push(q1->right);
            if (q1 == last){
                last = q.back();
                res.push_back(vector<int>());
                level++;
            }
        }
        res.pop_back();
        return res;
    }
};


int main(){
    Solution s;
    return 0;
}
