# [题目](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

* Remove Nth Node From End of List

> Given a linked list, remove the n-th node from the end of list and return its head.

* Example:

> Given linked list: 1->2->3->4->5, and n = 2.

> After removing the second node from the end, the linked list becomes 1->2->3->5.

* Note:

> Given n will always be valid.

* Follow up:

> Could you do this in one pass?


# 代码

```cpp
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        // fast 先走 n 步
        for (int i = 0; i < n; i++){
            fast = fast->next;
        }

        // n = 链表长度 m 时，相当于去除链表第一个
        if (!fast) return head->next;

        // fast, slow 一起走 m - 1 步
        while (fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$
* 空间复杂度: $O(1)$

# 思路
* 找倒数第 $N + 1$ 个节点

> 为了去除倒数第 $N$ 个节点，需要找到它前面的那个节点，如为了去除链表 1 -> 2 -> 3 -> 4 -> 5 的倒数第 2 个节点，需要找到节点 3 ，然后让 3 指向 5 即可。即需要找倒数第 $N + 1$ 个节点， 若总长度为 $M$ ，即是找正数第 $M - (N + 1)$ 个节点。

* 快慢指针
	* 快指针先走 $N$ 步
		* $N = M$ 时，即去除倒数第 $M$ 个，也就是正数第一个
	* 然后快慢指针一起走，快指针走到最后一个数字时 (总共走了 $M - 1$ 步)，则慢指针走了 $M - 1 - N$ 步 


