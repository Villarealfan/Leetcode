#include "../include/tools.h"

class Solution {
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

int main(){
    Solution so;
    Tools tool;

    string line;
    vector<ListNode*> lists;
    cout << "输入:" << endl;
    while (getline(cin, line)){
        if (line == ":q!") break;
        ListNode* node = tool.stringToListNode(line);
        lists.push_back(node);
    }
    
    ListNode* res = so.mergeKLists(lists);
    string output = tool.listNodeToString(res);

    cout << "输出:\n" << output << endl;
    return 0;
}
