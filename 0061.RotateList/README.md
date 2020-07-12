# [题目](https://leetcode.com/problems/rotate-list/)

* Rotate List

> Given a linked list, rotate the list to the right by k places, where k is non-negative.

* Example 1:

> Input: 1->2->3->4->5->NULL, k = 2

> Output: 4->5->1->2->3->NULL

> Explanation:
```
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
```

* Example 2:

> Input: 0->1->2->NULL, k = 4

> Output: 2->0->1->NULL

* Explanation:
```
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
```

# 代码
```cpp
class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        if (!head || !head->next || k == 0) return head;
        ListNode* cur = head;

        // 计算链表长度
        int n = 1; // 长度
        while (cur->next){
            cur = cur->next;
            n++;
        }

        k %= n; // 避免循环找

        // 下以 head = 1->2->3->4->5, k = 2 为例
        cur->next = head; // 5->1

        // 走 n - k - 1 步，head 走到 3
        for (int i = 1; i < n - k; i++){
            head = head->next;
        }
        ListNode* res = head->next; // 4->5
        head->next = NULL; // 1->2->3->NULL
        return res;
    }
};
```

# 思路

* 需要找到第 n - k 个节点，其中 k%=n 处理过，避免循环 。因此，需要让链表从第 1 个节点开始走 n - k - 1步。
* 找到第 n - k  个节点后，断开链表，如上例，head = 1->2->3->4->5，k = 2， 找到节点 3，3 前面和后面的链表断开为 1->2->3 和 4->5->NULL，然后将两个拼接即可。