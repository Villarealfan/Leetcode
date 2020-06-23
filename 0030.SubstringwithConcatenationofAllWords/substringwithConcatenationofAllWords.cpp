#include "../include/tools.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return {};
        unordered_map<string, int> maps, temp;
        int n = words.size(), m = words[0].size();
        int endIndex = s.length() - m*n; // 遍历的最右端

        // 统计每个单词出现次数
        for (string& word: words) maps[word]++;

        // 滑动窗口逐一匹配
        for (int i = 0; i <= endIndex; i++){
            int k = 0; // 匹配的单词个数 
            while (k < n){
                string subs = s.substr(i + k*m, m); // 截取第 k 个子串
                if (maps.find(subs) != maps.end()){
                    // 子串是 maps 中的单词
                    temp[subs]++;
                    if (temp[subs] > maps[subs]){
                        // 使用次数比 maps 中还多
                        break;
                    }
                }
                else{
                    // 不在 maps 中
                    break;
                }
                k++;
            }
            //  n 个单词全部匹配上
            if (k == n){
                res.push_back(i);
            }
            temp.clear(); // 每次匹配完清空
        }
        return res;
    }
};

int main(){
    Solution so;
    Tools tool;

    string s,line;
    cout << "输入 s:" << endl;
    getline(cin, s);
    
    cout << "输入 words:" << endl;
    getline(cin, line);
    vector<string> words = tool.split(line, ",");
    
    vector<int> res = so.findSubstring(s, words);
    string ouput = tool.vectorToString(res);

    cout << "输出:\n" << ouput << endl;
    return 0;
}
