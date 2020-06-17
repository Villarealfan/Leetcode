#include "../include/tools.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string item;
        dfs(res, item, n, n);
        return res;
    }

    void dfs(vector<string>& res, string item, int l, int r){
        if (l > r) return;
        if (l == 0 && r == 0){
            res.push_back(item);
            return;
        } 
        if (l > 0) dfs(res, item + "(", l - 1, r);
        if (r > 0) dfs(res, item + ")", l, r - 1);
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    int n = atoi(line.c_str());
    vector<string> res = so.generateParenthesis(n);
    cout << "输出:" << endl;
    for (string& item: res){
        cout << item << endl;
    }
    return 0;
}
