# include "../include/tools.h"

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>{};
        return helper(0, n);
    }

private:
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> trees;
        if (start == end){
            trees.push_back(NULL);
        }
        for (int i = start; i < end; i++){
            vector<TreeNode*> left = helper(start, i);
            vector<TreeNode*> right = helper(i + 1, end);
            for (TreeNode* ltree: left){
                for (TreeNode* rtree: right){
                    TreeNode* tree = new TreeNode(i + 1);
                    tree->left = ltree;
                    tree->right = rtree;
                    trees.push_back(tree);
                }
            }
        }
        return trees;
    }
};

int main(){
    Solution so;
    int n;
    cout << "输入:" << endl;
    cin >> n;
    vector<TreeNode*> res = so.generateTrees(n);
    return 0;
}
