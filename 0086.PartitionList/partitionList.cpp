# include "../include/tools.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* less_head = new ListNode(0);
        ListNode* more_head = new ListNode(0);
        ListNode* less = less_head, *more = more_head;
        while (head){
            if (head->val < x){
                less->next = new ListNode(head->val);
                less = less->next;
            }
            else{
                more->next = new ListNode(head->val);
                more = more->next;
            }
            head = head->next;
        }
        less->next = more_head->next;
        return less_head->next;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入 head:" << endl;
    getline(cin, line);
    ListNode* head = tool.stringToListNode(line);
    int x;
    cout << "输入 x:" << endl;
    cin >> x;
    ListNode* node = so.partition(head, x);
    string output = tool.listNodeToString(node);
    cout << "输出:\n" << output << endl;
    return 0;
}
