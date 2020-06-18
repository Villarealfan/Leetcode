# [题目](https://leetcode.com/problems/swap-nodes-in-pairs/)

* Swap Nodes in Pairs
> Given a linked list, swap every two adjacent nodes and return its head.

> You may **not** modify the values in the list's nodes, only nodes itself may be changed.

* Example:

> Given 1->2->3->4, you should return the list as 2->1->4->3.


# 代码

```cpp
class Solution{
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy, *cur = head;
        while (cur && cur->next){
            pre->next = cur->next;
            pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = pre->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$
* 空间复杂度: $O(1)$

# 思路
循环里是将

    0   -->   1   -->   2   -->   3   -->   4
    ↑         ↑    
    pre      cur

变为

    0   -->   2   -->   1   -->   3   -->   4
                        ↑         ↑    
                       pre       cur

拆分来看：

1. **0 --> 2**
```cpp
pre->next = cur->next;
```

    -------------------->
    ↑                   ↓
    0         1   -->   2   -->   3   -->   4
    ↑         ↑    
    pre      cur

2. **pre 从 0 前移到 2 处**
```cpp
pre = pre->next;
```

    -------------------->
    ↑                   ↓
    0         1   -->   2   -->   3   -->   4
              ↑         ↑    
              cur       pre

3. **1 --> 3**
```cpp
cur->next = pre->next;
```

              -------------------->
    ----------↑--------->         ↓
    ↑         ↑         ↓         ↓
    0         1         2   -->   3   -->   4
              ↑         ↑    
              cur       pre

4. **2 --> 1**
```cpp
pre->next = cur;
```

              -------------------->
    ----------↑--------->         ↓
    ↑         ↑         ↓         ↓
    0         1   <--   2   -->   3   -->   4
              ↑         ↑    
              cur       pre  
也就是
    
    0   -->   2   -->   1   -->   3   -->   4
              ↑         ↑    
             pre       cur

5. **pre 和 cur 均前移一步**
```cpp
pre = pre->next; 
cur = cur->next;
```

       0   -->   2   -->   1   -->   3   -->   4
                           ↑         ↑    
                          pre       cur
