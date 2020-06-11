#include "../include/tools.h"

class Solution{
public:
    string convert(string s, int numRows){ 
        int n = s.length();
        if (numRows <= 1 || numRows >= n) return s;
        string res;
        int diff = 2*(numRows - 1);
        for (int i = 0; i < numRows; i++){
            for (int j = i; j < n; j += diff){
                res +=  s[j];
                if (i > 0 && i < numRows - 1){
                    int k = j + diff - 2*i;
                    if (k < n){
                        res += s[k];
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution so;

    string line;
    cout << "输入字符串:" << endl;
    getline(cin, line);
    string s = line;
    cout << "输入 numRows:" << endl;
    getline(cin, line);
    int numRows = atoi(line.c_str());
    string output = so.convert(s, numRows);
    cout << "输出:\n" << output  << endl;
    return 0;
}
