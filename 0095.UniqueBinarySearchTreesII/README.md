# [题目](https://leetcode.com/problems/unique-binary-search-trees-ii/)

* Unique Binary Search Trees II

> Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

* Example:
```
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

* Constraints:

> 0 <= n <= 8

# 代码
```cpp
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
```

# 思路

* 递归
