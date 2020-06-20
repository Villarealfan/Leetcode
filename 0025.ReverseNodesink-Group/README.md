<script src="mermaid.full.min.js"></script>
# [题目](https://leetcode.com/problems/reverse-nodes-in-k-group/)

* Reverse Nodes in k-Group
> Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

> k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

* Example:

> Given this linked list: 1->2->3->4->5

>- For k = 2, you should return: 2->1->4->3->5

>- For k = 3, you should return: 3->2->1->4->5

* Note:

> Only constant extra memory is allowed.
> You may not alter the values in the list's nodes, only nodes itself may be changed.


# 代码

```cpp
class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy, *cur = dummy, *nex;

        // 统计链表长度
        int n = 0;
        while (cur->next){
            cur = cur->next;
            n++;
        }

        while (n >= k){ // 外循环
            cur = pre->next; // cur 移到当前模块第一个节点处
            for (int i = 1; i < k; i++){ // 内循环
                nex = cur->next; // nex 移到 cur 后
                cur->next = nex->next; // 1 --> 3
                nex->next = pre->next; // 2 --> 1
                pre->next = nex; // 0 --> 2
            }
            pre = cur; // pre 移到下个模块前一个节点处
            n -= k;
        }
        return dummy->next;
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$
* 空间复杂度: $O(1)$

# 思路

如 $n = 8, k = 3$ ，如下所示的 $head$ 链表
<div class="mermaid">
graph LR
0 --> 1 
2  
3 --> 4 
5 
6 --> 7  
8
NULL
pre((pre)) -.-> 0
cur((cur)) -.-> 1
subgraph one
1 --> 2 --> 3 
end
subgraph two
4 --> 5 --> 6
end
subgraph three
7 --> 8 -->NULL
end
</div>
将其分为两个循环：
## 1. 外循环: 
> 将链表翻转分为 k + k + ... + m 次处理, 其中 m = n %k  ，即每次处理 k 个节点的翻转，对于最后剩余的 m 个节点不处理。

如下图所示，先将原链表的第一部分的 3 个节点翻转，即 1-->2-->3 翻转为 3-->2-->1 ，结果为
<div class="mermaid">
graph LR
0 --> 3
2  
1 --> 4 
5 
6 --> 7
8
NULL
pre((pre)) -.-> 1
cur((cur)) -.-> 4
subgraph one
3 --> 2 --> 1
end
subgraph two
4 --> 5 --> 6
end
subgraph three
7 --> 8 -->NULL
end
</div>
再对第二部分的 3 个节点翻转，即 4-->5-->6 翻转为 6-->5-->4，结果为
<div class="mermaid">
graph LR
0 --> 3
2  
1 --> 6 
5 
4 --> 7 
8
NULL
pre((pre)) -.-> 4
cur((cur)) -.-> 7
subgraph one
3 --> 2 --> 1
end
subgraph two
6 --> 5 --> 4
end
subgraph three
7 --> 8 -->NULL
end
</div>
对于第三部分的 2 个节点 (7 --> 8) 不处理。

* Note
> 注意各个指针最后的位置
>- pre: 下一个需要处理模块的前面一个节点
>- cur: 当前处理模块的第一个节点

## 2. 内循环
> 对于长度为 k 的子链表进行翻转，可分为 k - 1 次调整

以第一部分 3 个节点 1-->2-->3 翻转为 3-->2-->1 为例：
<div class="mermaid">
graph LR
0 --> 1 
2  
3 --> 4 
5 
6 --> 7  
8
NULL
pre((pre)) -.-> 0
cur((cur)) -.-> 1
subgraph one
1 --> 2 --> 3 
end
subgraph two
4 --> 5 --> 6
end
subgraph three
7 --> 8 -->NULL
end
</div>
首先，将节点 1 后面的节点 2 调整到 0 的后面，即 0-->1-->2-->3 变为 0-->2--> 1-->3
<div class="mermaid">
graph LR
0 --> 2 
1 
3 --> 4 
5 
6 --> 7  
8
NULL
pre((pre)) -.-> 0
cur((cur)) -.-> 1
subgraph one
2 --> 1 --> 3 
end
subgraph two
4 --> 5 --> 6
end
subgraph three
7 --> 8 -->NULL
end
</div>
再将节点 1 后面的节点 3 调整到 0 的后面，即 0-->2-->1-->3 变为 0-->3--> 2-->1
<div class="mermaid">
graph LR
0 --> 3 
2 
1 --> 4 
5 
6 --> 7  
8
NULL
pre((pre)) -.-> 0
cur((cur)) -.-> 1
subgraph one
3 --> 2 --> 1
end
subgraph two
4 --> 5 --> 6
end
subgraph three
7 --> 8 -->NULL
end
</div>
由于节点 1 不调整，则这 k 个节点的逐一翻转，需要进行 k - 1 次。
因此，问题关键是如何进行逐一翻转，即将 cur 对应节点 (1) 后的节点 (3) 调整到 pre 对应节点 (0) 后面。
## 3. 逐一翻转
从上面发现，需要记录 cur 后面的节点，因此
### 3.1 记录 cur 后的节点为 nex
```cpp
nex = cur->next;
```
以 0-->1-->2-->3 变为 0-->2--> 1-->3 为例，如下图所示， nex 对应到节点 2
<div class="mermaid">
graph LR
0 --> 1 
2  
3 --> 4 
5 
6 --> 7  
8
NULL
pre((pre)) -.-> 0
cur((cur)) -.-> 1
nex((nex)) -.-> 2
subgraph one
1 --> 2 --> 3 
end
subgraph two
4 --> 5 --> 6
end
subgraph three
7 --> 8 -->NULL
end
</div>
### 3.2 重新连接链表
> 从后往前连接，即
>
> - 1 --> 3
```cpp
cur->next = nex->next
```
>- 2 --> 1
```cpp
nex->next = pre->next
```
>- 0 --> 2
```cpp
pre->next = nex
```

重新连接后上面链表变为，
<div class="mermaid">
graph LR
0 --> 2 
1  
3 --> 4 
5 
6 --> 7  
8
NULL
pre((pre)) -.-> 0
cur((cur)) -.-> 1
nex((nex)) -.-> 2
subgraph one
2 --> 1 --> 3 
end
subgraph two
4 --> 5 --> 6
end
subgraph three
7 --> 8 -->NULL
end
</div>
