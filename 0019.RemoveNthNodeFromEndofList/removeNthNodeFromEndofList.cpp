#include "../include/tools.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = head, *slow = head;
        for (int i = 0; i <= n; i++){
            fast = fast->next;
        }
        while (fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入 head:" << endl;
    getline(cin, line);
    ListNode* head = tool.stringToListNode(line);

    cout << "输入 n:" << endl;
    getline(cin, line);
    int n = atoi(line.c_str());

    ListNode* node = so.removeNthFromEnd(head, n);
    string output = tool.listNodeToString(node);

    cout << "输出:\n" << output << endl; 
    return 0;
}
