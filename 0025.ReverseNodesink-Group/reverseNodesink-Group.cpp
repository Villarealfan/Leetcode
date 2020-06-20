#include "../include/tools.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy, *cur = dummy, *nex;
        
        // 统计链表长度
        int n = 0;
        while (cur->next){
            cur = cur->next;
            n++;
        }

        while (n >= k){ // 外循环
            cur = pre->next; // cur 移到当前模块第一个节点处
            for (int i = 1; i < k; i++){ // 内循环
                nex = cur->next; // nex 移到 cur 后
                cur->next = nex->next; // 1 --> 3
                nex->next = pre->next; // 2 --> 1
                pre->next = nex; // 0 --> 2
            }
            pre = cur; // pre 移到下个模块前一个节点处
            n -= k; 
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
    cout << "输入 k:" << endl;
    getline(cin, line);
    int k = atoi(line.c_str());

    ListNode* node = so.reverseKGroup(head, k);
    string output = tool.listNodeToString(node);
    cout << "输出:\n" << output << endl;
    return 0;
}
