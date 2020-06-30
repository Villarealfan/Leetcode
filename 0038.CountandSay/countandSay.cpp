#include "../include/tools.h"

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; i++){
            string temp;
            int count = 1;
            int m = res.length();
            char c = res[0];
            for (int j = 1; j < m; j++){
                if (res[j] != res[j - 1]){
                    temp += to_string(count) + c;
                    c = res[j];
                    count = 1;
                }
                else{
                    count++;
                }
            }
            temp += to_string(count) + c;
            res = temp;
        }
        return res;
    }
};

int main(){
    Solution so;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    int n = atoi(line.c_str());
    string output = so.countAndSay(n);
    cout << "输出:\n" << output << endl;
    return 0;
}
