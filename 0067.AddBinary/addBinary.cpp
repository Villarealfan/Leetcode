#include "../include/tools.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0, sum = 0;
        // 从后往前加
        while (i >= 0 || j >= 0){
            sum = carry;
            // a,b 不到头就加
            if (i >= 0){
                sum += (a[i] - '0');
                i--;
            }
            if (j >= 0){
                sum += (b[j] - '0');
                j--;
            }
            // 注意是二进制
            res.push_back(sum%2 + '0');
            carry = sum/2;
        }
        
        // 最后进位
        if (carry != 0){
            res.push_back(carry + '0');
        }
        // 翻转
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution so;
    string a, b;
    cout << "输入 a:" << endl;
    getline(cin, a);
    cout << "输入 b:" << endl;
    getline(cin, b);
    string output = so.addBinary(a, b);
    cout << "输出:\n" << output << endl;
    return 0;
}
