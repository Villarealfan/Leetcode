#include "../include/tools.h"

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char,int> symbols = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int n = s.length();
        for (int i = 0; i < n; i++){
            if (i < n - 1 && symbols[s[i]] < symbols[s[i + 1]]){
                res -= symbols[s[i]];
            }
            else{
                res += symbols[s[i]];
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
    int output = so.romanToInt(line);

    cout << "输出:\n" << output  << endl;
    return 0;
}
