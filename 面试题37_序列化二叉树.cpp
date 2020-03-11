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

class Codec {
public:

    string serialize(TreeNode* root) {
        string res;
        if(root==NULL) return res;
        char tempC[100];
        snprintf(tempC, sizeof(tempC), "%d", root->val);
        res = res + tempC + ",";
        if(root->left == NULL){
            res += "$,";
        }
        else{
            res += serialize(root->left);
        }
        if(root->right == NULL){
            res += "$,";
        }
        else{
            res += serialize(root->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len=data.size();
        if(len == 0) return NULL;
        int index = 0;
        TreeNode* root = subDeserialize(data, index);
        return root;
    }

    TreeNode* subDeserialize(string& data, int &index){
        if(index >= data.length()) return NULL;
        int n = data.find_first_of(",", index);
        if(n == string::npos) return NULL;
        string sval = data.substr(index, n-index);
        index = n+1;
        if(sval == "$"){
            return NULL;
        }
        int val = stoi(sval);
        TreeNode* root = new TreeNode(val);
        
        root->left = subDeserialize(data, index);
        root->right = subDeserialize(data, index);
        return root;
    }
};

int main(){
    string s = "100,";
    s = s.substr(0, 1);
    cout << stoi(s) <<endl;
    return 0;
}
