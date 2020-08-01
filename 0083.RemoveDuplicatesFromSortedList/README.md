# [题目](https://leetcode.com/problems/remove-duplicates-from-sorted-list)

* Given a sorted linked list, delete all duplicates such that each element appear only once.

* Example 1:

> Input: 1->1->2

> Output: 1->2

* Example 2:

> Input: 1->1->2->3->3

> Output: 1->2->3

# 代码

```cpp
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* node = head;
        while (node->next){
            if (node->next->val == node->val){
                node->next = node->next->next;
            }
            else{
                node = node->next;
            }
        }
        return head;
    }
};
```

# 思路

* 简单实现，注意不要把重复的干掉。
