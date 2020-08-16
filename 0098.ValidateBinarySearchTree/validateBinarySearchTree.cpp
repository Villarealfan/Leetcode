# include "../include/tools.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return inorder(root, pre);
    }

private:
    bool inorder(TreeNode*& root, TreeNode*& pre){
        if (root == NULL) return true;
        if (!inorder(root->left, pre)) return false;
        if (pre != NULL && root->val <= pre->val) return false;
        pre = root;
        return inorder(root->right, pre);
    }
};

int main(){
    Solution so;
    Tools tool;
    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    TreeNode* root = tool.stringToTreeNode(line);
    bool res = so.isValidBST(root);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
