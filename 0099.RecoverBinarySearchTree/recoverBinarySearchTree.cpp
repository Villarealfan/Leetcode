# include "../include/tools.h"

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;

        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;

        helper(root, first, second, prev);
        if (first != NULL && second != NULL) swap(first->val, second->val);
        return;
    }

private:
    void helper(TreeNode*& root, TreeNode*& first, TreeNode*& second, TreeNode*& prev){
        if (root == NULL) return;
        helper(root->left, first, second, prev);

        if (prev != NULL && prev->val >= root->val){
            if (first == NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;
        helper(root->right, first, second, prev);
    }
};

int main(){
    Solution so;
    Tools tool;
    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    TreeNode* root = tool.stringToTreeNode(line);
    so.recoverTree(root);
    return 0;
}
