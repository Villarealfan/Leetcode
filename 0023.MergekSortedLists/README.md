# [题目](https://leetcode.com/problems/merge-k-sorted-lists/)

* Merge k Sorted Lists

> Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

* Example:

> Input:
   
    [
      1->4->5,
      1->3->4,
      2->6
    ]
> Output: 
     
     1->1->2->3->4->4->5->6


# 代码

```cpp
class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int n = lists.size() - 1;
        return mySort(lists, 0, n);
    }

    ListNode* mySort(vector<ListNode*>& lists, int l, int r){
        if (l >= r) return lists[l];
        int mid = l + (r - l)/2;
        ListNode* l1 = mySort(lists, l, mid);
        ListNode* l2 = mySort(lists, mid + 1, r);
        return myMerge(l1, l2);
    }

    ListNode* myMerge(ListNode* l1, ListNode* l2){
        if (!l1) return l2;
        if (!l2) return l1;
        while (l1 && l2){
            if (l1->val < l2->val){
                l1->next = myMerge(l1->next, l2);
                return l1;
            }
            else{
                l2->next = myMerge(l1, l2->next);
                return l2;
            }
        }
        return NULL;
    }
};
```

# 复杂度
* 时间复杂度: $O(nlogk)$, $k$ 为 lists 中链表个数，$n$ 为最长链表长度
* 空间复杂度: $O(1)$

# 思路
* 归并排序


