#include "../include/tools.h"

class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        if (!head || !head->next || k == 0) return head;
        ListNode* cur = head;
        
        // 计算链表长度
        int n = 1; // 长度
        while (cur->next){
            cur = cur->next;
            n++;
        }

        k %= n; // 避免循环找
        
        // 下以 head = 1->2->3->4->5, k = 2 为例
        cur->next = head; // 5->1

        // 走 n - k - 1 步
        for (int i = 1; i < n - k; i++){
            head = head->next;
        }
        ListNode* res = head->next; // 4->5
        head->next = NULL; // 1->2->3->NULL
        return res;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入 head:" << endl;
    getline(cin, line);
    ListNode* head = tool.stringToListNode(line);
    int k;
    cout << "输入 k:" << endl;
    cin >> k;

    ListNode* node = so.rotateRight(head, k);
    string output = tool.listNodeToString(node);
    cout << "输出:\n" << output << endl;
    return 0;
}
