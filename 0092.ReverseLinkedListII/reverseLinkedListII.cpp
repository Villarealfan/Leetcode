# include "../include/tools.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        for (int i = 1; i < m; i++){
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        ListNode* nex = cur->next;
        for (int i = 1; i <= n - m; i++){
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
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
    int m, n;
    cout << "输入 m, n:" << endl;
    cin >> m >> n;
    ListNode* node = so.reverseBetween(head, m, n);
    string output = tool.listNodeToString(node);
    cout << "输出:\n" << output << endl;
    return 0;
}
