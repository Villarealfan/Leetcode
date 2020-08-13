# [题目](https://leetcode.com/problems/binary-tree-inorder-traversal/)

* Binary Tree Inorder Traversal

> Given a binary tree, return the inorder traversal of its nodes' values.

* Example:

```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
```

* Follow up: 
> Recursive solution is trivial, could you do it iteratively?

# 代码
```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(res, root);
        return res;
    }

private:
    void helper(vector<int>& res, TreeNode*& root){
        if (root == NULL) return;
        helper(res, root->left);
        res.push_back(root->val);
        helper(res, root->right);
    }
};
```

# 思路

* DFS
