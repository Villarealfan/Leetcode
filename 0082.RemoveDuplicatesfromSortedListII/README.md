# [题目] (https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

* Remove Duplicates from Sorted List II

> Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

> Return the linked list sorted as well.

* Example 1:

> Input: 1->2->3->3->4->4->5

> Output: 1->2->5

* Example 2:

> Input: 1->1->1->2->3

> Output: 2->3

# 代码

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        while (cur->next && cur->next->next){
            if (cur->next->val == cur->next->next->val){
                int sameVal = cur->val;
                while (cur->next && cur->next->val == sameVal){
                    cur->next = cur->next->next;
                }
            }
            else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
```

# 思路

* 判断前后两个节点的值是否相同
