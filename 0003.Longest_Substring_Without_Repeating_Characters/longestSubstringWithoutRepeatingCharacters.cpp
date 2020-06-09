#include "../include/tools.h"

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int index[256];
        memset(index, -1, sizeof(int)*256);
        int res = 0, l = 0, n = s.length();
        for (int r = 0; r < n; r++){
            l = max(l, index[s[r]] + 1);
            res = max(res, r - l + 1);
            index[s[r]] = r;
        }
        return res;
    }
};

int main(){
    Solution so;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);

    int output = so.lengthOfLongestSubstring(line);

    cout << "输出:\n" << output  << endl;
    return 0;
}
