#include "../include/tools.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        while (cur->next && cur->next->next){
            if (cur->next->val == cur->next->next->val){
                int sameVal = cur->val;
                while (cur->next && cur->next->val == sameVal){
                    cur->next = cur->next->next;
                }
            }
            else{
                cur = cur->next;
            }
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
    ListNode* node = so.deleteDuplicates(head);
    string res = tool.listNodeToString(node);
    cout << "输出:\n" << res << endl;
    return 0;
}
