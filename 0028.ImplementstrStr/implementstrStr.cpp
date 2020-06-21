#include "../include/tools.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.length(), m = needle.length();
        for (int i = 0; i <= n - m; i++){
            if (haystack.substr(i, m) == needle){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution so;
    string haystack, needle;
    cout << "输入 haystack:" << endl;
    getline(cin, haystack);
    cout << "输入 needle:" << endl;
    getline(cin, needle);
    int output = so.strStr(haystack, needle);
    cout << "输出:\n" << output << endl;
    return 0;
}
