#include "../include/tools.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 分母为 1，结果为其本身
        if (divisor == 1) return dividend;
        
        // 同号+, 异号-
        int sign;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)){
            sign = 1;
        }
        else{
            sign = -1;
        }

        long long a = abs((long long)dividend), b = abs((long long) divisor), res = 0;
        
        /*
         * a = b*2^m1 + b*2^m2 + ... + b*2^mn + c
         * res = 2^m1 + 2^m2 + ... + 2^mn
         */
        while (a >= b){
            long long temp = b, m = 1;
            // 求满足 a >= b * 2^m 的最大 m 
            while (a >= (temp<<1)){
                temp<<=1; // b*2
                m<<=1; // m*2
            }
            a -= temp;
            res += m;
        }

        // 结果处理，考虑正负，避免越界
        if (sign == 1){
            if (res >= INT_MAX){
                return INT_MAX;
            }
            else{
                return (int)res;
            }
        }
        else{
            if (-res >= INT_MIN){
                return (int)(-res); 
            }
            else{
                return INT_MIN;
            }
        }
    }
};

int main(){
    Solution so;
    string line;
    cout << "输入 dividend:" << endl;
    getline(cin, line);
    int dividend = atoi(line.c_str());
    cout << "输入 divisor:" << endl;
    getline(cin, line);
    int divisor = atoi(line.c_str());
    int output = so.divide(dividend, divisor);
    cout << "输出:\n" << output << endl;
    return 0;
}
