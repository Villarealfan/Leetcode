# [题目](https://leetcode.com/problems/partition-list/)

* Partition List

> Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

> You should preserve the original relative order of the nodes in each of the two partitions.

* Example:

> Input: head = 1->4->3->2->5->2, x = 3

> Output: 1->2->2->4->3->5

# 代码

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* less_head = new ListNode(0);
        ListNode* more_head = new ListNode(0);
        ListNode* less = less_head, *more = more_head;
        while (head){
            if (head->val < x){
                less->next = new ListNode(head->val);
                less = less->next;
            }
            else{
                more->next = new ListNode(head->val);
                more = more->next;
            }
            head = head->next;
        }
        less->next = more_head->next;
        return less_head->next;
    }
};
```

# 思路

* 将小于 x 的放到 less 链表中([1,2,2])，其他放在 more 链表中([4,3,5])，将 more
  连接到 less 后面，即 2 -> 4
