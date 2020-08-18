# [题目](https://leetcode.com/problems/recover-binary-search-tree/)

* Recover Binary Search Tree

> Two elements of a binary search tree (BST) are swapped by mistake.

> Recover the tree without changing its structure.

* Example 1:
```
Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
```

* Example 2:
```
Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
```

* Follow up:

> A solution using O(n) space is pretty straight forward.
> Could you devise a constant space solution?

# 代码
```cpp
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
```

# 思路

* 中序遍历
