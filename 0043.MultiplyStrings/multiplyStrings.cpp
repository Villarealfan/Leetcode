#include "../include/tools.h"

class Solution{
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0") return "0";
        int m = num1.length(), n = num2.length();
        string res(m + n, '0');
        for (int i = m - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                int sum = (num1[i] - '0')*(num2[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = sum%10 + '0';
                res[i + j] += sum/10; 
            }
        }
        res.erase(0, res.find_first_not_of('0'));
        return res;
    }
};

int main(){
    Solution so;

    string num1, num2;
    cout << "输入 num1:" << endl;
    getline(cin, num1);
    cout << "输入 num2:" << endl;
    getline(cin, num2);

    string output = so.multiply(num1, num2);
    cout << "输出:\n" << output << endl;
    return 0;
}
