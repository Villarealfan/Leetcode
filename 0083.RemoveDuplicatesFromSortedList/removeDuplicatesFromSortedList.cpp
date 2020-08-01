#include "../include/tools.h"

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* node = head;
        while (node->next){
            if (node->next->val == node->val){
                node->next = node->next->next;
            }
            else{
                node = node->next;
            }
        }
        return head;
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
