#include "../include/tools.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy, *cur = head;
        while (cur->next){
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

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    ListNode* head = tool.stringToListNode(line);

    ListNode* node = so.swapPairs(head);
    string output = tool.listNodeToString(node);
    cout << "输出:\n" << output << endl;
    return 0;
}
