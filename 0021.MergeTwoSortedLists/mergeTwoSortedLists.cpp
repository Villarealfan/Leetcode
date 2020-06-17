#include "../include/tools.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        while (l1 && l2){
            if (l1->val < l2->val){
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else{
                l2->next = mergeTwoLists(l1, l2->next);
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
    cout << "输入 l1:" << endl;
    getline(cin, line);
    ListNode* l1 = tool.stringToListNode(line);
    cout << "输入 l2:" << endl;
    getline(cin, line);
    ListNode* l2 = tool.stringToListNode(line);

    ListNode* node = so.mergeTwoLists(l1, l2);
    string output = tool.listNodeToString(node);

    cout << "输出:\n" << output << endl;
    return 0;
}
