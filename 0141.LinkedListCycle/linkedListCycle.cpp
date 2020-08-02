#include "../include/tools.h"

class Solution{
    public:
    bool hasCycle(ListNode* head){
        if (!head || !head->next) return false;
        ListNode* fast = head, *slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    ListNode* head = tool.stringToListNode(line);
    bool res = so.hasCycle(head);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
