#include "../include/tools.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        // fast 先走 n 步
        for (int i = 0; i < n; i++){
            fast = fast->next;
        }
        
        // n = 链表长度 m 时，相当于去除链表第一个
        if (!fast) return head->next;

        // fast, slow 一起走 m - 1 步
        while (fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
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
