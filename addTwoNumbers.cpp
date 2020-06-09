#include "../include/tools.h"

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        int carry = 0;
        while (l1 || l2 || carry){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            pre->next = new ListNode(sum%10);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            pre = pre->next;
            carry = sum/10;
        }
        return dummy->next;
    }
};

int main(){
    Tools tool;
    Solution so;

    cout << "输入:" << endl;
    string line;
    getline(cin, line);
    ListNode* l1 = tool.stringToListNode(line);
    getline(cin, line);
    ListNode* l2 = tool.stringToListNode(line);

    ListNode* res = so.addTwoNumbers(l1, l2);
    string output = tool.listNodeToString(res);

    cout << "输出:\n" << output << endl;
    return 0;
}
