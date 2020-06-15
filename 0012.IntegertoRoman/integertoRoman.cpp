#include "../include/tools.h"

class Solution {
public:
    string intToRoman(int num) {
        string res;
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for (int i = 0; i < 13; i++){
            while (num >= value[i]){
                num -= value[i];
                res += symbol[i];
            }
        }
        return res;
    }
};

int main(){
    Solution so;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    int num = atoi(line.c_str());
    string output = so.intToRoman(num);

    cout << "输出:\n" << output  << endl;
    return 0;
}
