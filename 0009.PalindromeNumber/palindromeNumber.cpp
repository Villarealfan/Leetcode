#include "../include/tools.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x%10 == 0) return false;
        int y = 0;
        while (x > y){
            y = y*10 + x%10;
            x /= 10;
        }
        return (x == y || x == y/10); // 1221, 12321
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    int x = atoi(line.c_str());
    bool res = so.isPalindrome(x);
    string output = tool.boolToString(res); 
    cout << "输出:\n" << output  << endl;
    return 0;
}
