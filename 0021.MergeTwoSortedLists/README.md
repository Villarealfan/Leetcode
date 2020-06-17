# [题目](https://leetcode.com/problems/merge-two-sorted-lists/)

* Merge Two Sorted Lists

> Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

* Example:

> Input: 1->2->4, 1->3->4

> Output: 1->1->2->3->4->4


# 代码

```cpp
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        while (l1 && l2){
            if (l1->val < l2->val){
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else{
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
        return NULL;
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$
* 空间复杂度: $O(1)$

# 思路
* 递归


