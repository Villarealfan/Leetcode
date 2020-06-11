#include "../include/tools.h"

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0){
            res = res*10 + x%10;
            x /= 10;
        }
        if (res >= INT_MIN && res <= INT_MAX){
            return (int)res;
        }
        else{
            return 0;
        }
    }
};

int main(){
    Solution so;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    int x = atoi(line.c_str());
    int output = so.reverse(x);
    cout << "输出:\n" << output  << endl;
    return 0;
}
