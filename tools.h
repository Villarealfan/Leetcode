#ifndef TOOLS_H
#define TOOLS_H

#include "global.h"

class Tools{
public:
    vector<string> split(string s, string p){
        vector<string> res;
        s += p;
        int n = s.length(), m = p.length();
        for (int i = 0; i < n; i++){
            int j = s.find(p, i);
            if (j < n){
                string subs = s.substr(i, j - i);
                res.push_back(subs);
                i = j + m - 1;
            }
        }
        return res;
    }

    vector<int> stringToVector(string s){
        vector<int> res;
        if (s.empty()) return res;
        stringstream ss;
        ss.str(s);
        string item;
        char delim = ',';
        while (getline(ss, item, delim)){
            res.push_back(stoi(item));
        }
        return res;
    }

    string vectorToString(vector<int> nums){
        if (nums.empty()) return "";
        int n = nums.size();
        string res;
        for (int i = 0; i < n - 1; i++){
            res += to_string(nums[i]) + ",";
        }
        res += to_string(nums[n - 1]);
        return res;
    }

    string listNodeToString(ListNode *head){
        if (!head) return "";
        string res;
        while (head->next){
            res += to_string(head->val) + ",";
            head = head->next;
        }
        res += to_string(head->val);
        delete head;
        return res;
    }

    ListNode* stringToListNode(string s){
        vector<int> list = stringToVector(s);
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        int n = list.size();
        for (int i = 0; i < n; i++){
            ptr->next = new ListNode(list[i]);
            ptr = ptr->next;
        }
        ptr = dummy->next;
        delete dummy;
        return ptr;
    }

    string boolToString(bool input){
        return input ? "True" : "False";
    }

    ListNode* listNodeAddCycle(ListNode* head, int pos){
        if (pos == -1 || !head || !head->next) return head;
        ListNode* dummy = head, *cur = head, *tail = NULL;
        int n = 0;
        while (cur->next){
            if (pos == n) tail = cur;
            cur = cur->next;
            n++;
        }
        cur->next = tail;
        return dummy;
    }

    vector<vector<int> > getRandomMatrix(int n){
        int m = n*n;
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        bool used[m + 1];
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                srand(time(0));
                int num = rand()% m + 1;
                while (used[num]){
                    num = rand()% m + 1;
                }
                matrix[i][j] = num;
                used[num] = true;
            }
        }
        return matrix;
    }
};



#endif //TOOLS_H

