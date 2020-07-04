#include "../include/tools.h"

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > maps;
        for (string& str: strs){
            string key = str;
            sort(key.begin(), key.end());
            maps[key].push_back(str); 
        }
        for (auto& item: maps){
            res.push_back(item.second);
        }
        return res;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<string> strs = tool.split(line, ",");

    vector<vector<string> > res = so.groupAnagrams(strs);
    cout << "输出:" << endl;
    for (auto& item: res){
        for (string str: item){
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
