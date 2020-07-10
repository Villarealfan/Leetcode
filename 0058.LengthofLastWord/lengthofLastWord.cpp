#include "../include/tools.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.length() - 1;
        // "hello  word    " , tail 到 d 字符处
        while (tail >= 0 && s[tail] == ' '){
            tail--;
        }
        // 计算 word 的长度
        while (tail >= 0 && s[tail] != ' '){
            len++;
            tail--;
        }
        return len;
    }
};

int main(){
    Solution so;
    string s;
    cout << "输入:" << endl;
    getline(cin, s);

    int output = so.lengthOfLastWord(s);
    cout << "输出:\n" << output << endl;

    return 0;
}
