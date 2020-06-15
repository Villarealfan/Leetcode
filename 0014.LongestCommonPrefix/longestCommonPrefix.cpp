#include "../include/tools.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int n = strs.size(), m = strs[0].length();
        string res;
        for (int j = 0; j < m; j++){
            char c = strs[0][j];
            for (int i = 1; i < n; i++){
                if (j >= strs[i].length() || strs[i][j] != c){
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};

int main(){
    Solution so;

    string line;
    cout << "输入:"<< endl;
    getline(cin, line);

    vector<string> strs;
    stringstream ss;
    ss.str(line);

    char delim = ',';
    string item;
    while (getline(ss, item, delim)){
        strs.push_back(item);
    }
    string output = so.longestCommonPrefix(strs);

    cout << "输出:\n" << output  << endl;
    return 0;
}
