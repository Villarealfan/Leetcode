# include "../include/tools.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(res, root);
        return res;
    }

private:
    void dfs(vector<int>& res, TreeNode*& root){
        if (!root) return;
        dfs(res, root->left);
        res.push_back(root->val);
        dfs(res, root->right);
    }
};

int main(){
    Solution so;
    Tools tool;
    string input;
    cout << "输入:" << endl;
    getline(cin, input);
    TreeNode* root = tool.stringToTreeNode(input);
    vector<int> res = so.inorderTraversal(root);
    string output = tool.vectorToString(res);
    cout << "输出:\n" << output << endl;

}
