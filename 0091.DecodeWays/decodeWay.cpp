#include "../include/tools.h"

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int one = 1, two = 1, n = s.length();
        for (int i = 1; i < n; i++){
            if (s[i] == '0'){
                one  = 0;
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')){
                one = one + two;
                two = one - two;
            }
            else{
                two = one;
            }
        }
        return one;
    }
};


int main(){
    Solution so;
    string s;
    cout << "输入:" << endl;
    getline(cin, s);
    int output = so.numDecodings(s);
    cout << "输出:\n" << output << endl;
    return 0;
}
