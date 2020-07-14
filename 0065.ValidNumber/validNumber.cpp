#include "../include/tools.h"

class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        // 去掉头尾空格
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        
        int n = s.length();
        bool point = false; // 是否出现小数点
        bool e = false; // 是否出现 e
        bool number = false; // 是否为数字
        bool number_after_e = true; // e 后面是否为数字
        for (int i = 0; i < n; i++){
            if (s[i] >= '0' && s[i] <= '9'){
                number = true;
                number_after_e = true;
            }
            else if (s[i] == '.'){
                // 小数点不能在 e 后，也不能出现两次
                if (e || point){
                    return false;
                }
                point = true;
            }
            else if (s[i] == 'e'){
                // e 不能出现两次，e 前必须有数字
                if (e || !number){
                    return false;
                }
                e = true;
                number_after_e = false;
            }
            else if (s[i] == '+' || s[i] == '-'){
                // ± 号只能出现在第一位或者 e 后一位
                if (i != 0 && s[i - 1] != 'e'){
                    return false;
                }
            }
            else{
                // 出现其他符号
                return false;
            }
        }
        return number && number_after_e;
    }
};

int main(){
    Solution so;
    Tools tool;

    string s;
    cout << "输入:" << endl;
    getline(cin, s);
    bool res = so.isNumber(s);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
