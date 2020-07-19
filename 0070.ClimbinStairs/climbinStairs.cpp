#include "../include/tools.h"

class Solution {
public:
    int climbStairs(int n) {
        long first = 1, second = 1;
        while (n > 1){
            long temp = first + second;
            first = second;
            second = temp;
            n--;
        }
        return (int)second;
    }
};

int main(){
    Solution so;
    int n;
    cout << "输入:" << endl;
    cin >> n;
    int output = so.climbStairs(n);
    cout << "输出:\n" << output << endl;
    return 0;
}
