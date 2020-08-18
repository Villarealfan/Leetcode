# include "../include/tools.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){
    Solution so;
    Tools tool;
    string sp, sq;
    cout << "输入 p:" << endl;
    getline(cin, sp);
    cout << "输入 q:" << endl;
    getline(cin, sq);
    TreeNode* p = tool.stringToTreeNode(sp);
    TreeNode* q = tool.stringToTreeNode(sq);
    bool res = so.isSameTree(p, q);
    string output = tool.boolToString(res);
    cout << "输出:" << output << endl;
    return 0;
}
