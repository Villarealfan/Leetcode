#include "../include/tools.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        string item;
        string maps[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.length();
        dfs(res, item, digits, maps, 0, n);
        return res;
    }

    void dfs(vector<string>& res, string item, string& digits, string maps[], int i, int& n){
        if (i == n){
            res.push_back(item);
            return;
        }

        int index = (int)(digits[i] - '0');
        string s = maps[index];
        for (char c: s){
            item.push_back(c);
            dfs(res, item, digits, maps, i + 1, n);
            item.pop_back();
        }
    }
};

int main(){
    Solution so;
    
    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<string> res = so.letterCombinations(line);
    cout << "输出:" << endl;
    for (string item: res){
        cout << item << ",";
    }
    cout << endl;
    return 0;
}
