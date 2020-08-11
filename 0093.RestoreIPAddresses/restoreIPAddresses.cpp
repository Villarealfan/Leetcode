# include "../include/tools.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string item = "";
        dfs(res, item, s, 0, 0);
        return res;
    }

private:
    void dfs(vector<string>& res, string item, string s, int start, int count){
        if (count > 4) return;
        if (count == 4 && start == s.length()){
            res.push_back(item);
            return;
        }
        for (int i = 0; i < 3; i++){
            if (start + i >= s.length()) return;
            if (s[start] == '0' && i > 0) return;
            int temp = 0;
            for (int k = start; k <= start + i; k++){
                temp = 10*temp + (s[k] - '0');
            }
            if (temp >= 256) return;

            string ss = s.substr(start, i + 1);
            if (count < 3){
                ss = ss + ".";
            }
            dfs(res, item + ss, s, start + i + 1, count + 1);
        }
    }
};

int main(){
    Solution so;
    string s;
    cout << "输入:" << endl;
    getline(cin, s);
    vector<string> output = so.restoreIpAddresses(s);
    cout << "输出:" << endl;
    for (string& line: output){
        cout << line << endl;
    }
    return 0;
}
