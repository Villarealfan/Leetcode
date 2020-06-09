# [题目](https://leetcode.com/problems/add-two-numbers/)
* Add Two Numbers

>You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

>You may assume the two numbers do not contain any leading zero, except the number 0 itself.

* Example:

>Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

> Output: 7 -> 0 -> 8

>Explanation: 342 + 465 = 807.

# 代码
```cpp
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        int carry = 0;
        while (l1 || l2 || carry){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            pre->next = new ListNode(sum%10);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            pre = pre->next;
            carry = sum/10;
        }
        return dummy->next;
    }
};
```

# 复杂度
* 时间复杂度: O(max(m,n)) ，即需要遍历完较长的数组 
* 空间复杂度: O(1)

# 思路
* 逐个往后加，注意进位情况，如 l1 = 5 和 l2 = 6 , 结果 11 需要考虑进位上来的 1