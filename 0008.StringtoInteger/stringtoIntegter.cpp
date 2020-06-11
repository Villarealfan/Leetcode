#include "../include/tools.h"

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        long long res = 0;
        str.erase(0, str.find_first_not_of(" ")); // 去掉开头的空格
        bool isNegative = false;

        // 处理第一位，正负性
        int start = 0;
        if (str[0] == '+'){
            start++;
        }
        if (str[0] == '-'){
            start++;
            isNegative = true;
        }
        
        // 逐位计算
        int n = str.length();
        for (int i = start; i < n; i++){
            if (str[i] < '0' || str[i] > '9') break;
            res = res*10 + (int)(str[i] - '0');
        }
        
        // 处理负数
        if (isNegative){
            res = - res;
        }

        // 处理越界
        if (res > INT_MAX){
            return INT_MAX;
        }
        else if (res < INT_MIN){
            return INT_MIN;
        }
        else{
            return res;
        }
    }
};

int main(){
    Solution so;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    int output = so.myAtoi(line);
    cout << "输出:\n" << output  << endl;
    return 0;
}
