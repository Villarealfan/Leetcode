# [题目](https://leetcode.com/problems/reverse-linked-list-ii/)

* Reverse Linked List II

> Reverse a linked list from position m to n. Do it in one-pass.

* Note: 

> 1 ≤ m ≤ n ≤ length of list.

* Example:
```
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
```

# 代码
```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        for (int i = 1; i < m; i++){
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        ListNode* nex = cur->next;
        for (int i = 1; i <= n - m; i++){
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        return dummy->next;
    }
};
```

# 思路

* pre 挪到第 m - 1 个节点处，后面 n - m 个节点翻转
