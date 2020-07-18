#include "../include/tools.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int start = 0, n = words.size();
        while (start < n){
            int total = words[start].length(); //  添加字符的总长度
            int end = start + 1; // 该行使用最后一个单词的位置 

            // 不断添加空格和新单词
            while (end < n){
                int temp = words[end].length() + 1; // + 1 是有一个空格 
                if (total + temp > maxWidth){ 
                    break;
                }
                total += temp;
                end++;
            }

            string cur = ""; // 这行的字符串
            cur += words[start]; // 先把 start 这个放进去
            int diff = end - start - 1; // 能放置单词个数 - 1，可以认为单词间空挡个数

            if (end == n || diff == 0){
                // 最后一行或者只能放这一个单词时
                
                // 先把这些单词全拼接到 cur 后面，注意加空格
                for (int i = start + 1; i < end; i++){
                    cur += " ";
                    cur += words[i];
                }

                // 长度不够后面加空格
                for (int i = cur.length(); i < maxWidth; i++){
                    cur += " ";
                }
            }
            else{
                // maxWidth - total 是总空格个数, diff 是有多少个空挡
                int mimimum = (maxWidth - total)/diff + 1; //  单词间空挡最少需要的空格个数
                int residual = (maxWidth - total)%diff; // 每个空挡分 mimimum 个空格后，剩余的空格数

                for (int i = start + 1; i < end; i++){
                    //  多余的 residual 个空格在前面逐一分配
                    for (int k = 0; k < mimimum; k++){
                        // 先把最少的空格拼接上去
                        cur += " ";
                    }

                    // 多余的空格逐一使用
                    if (residual > 0){
                        cur += " ";
                        residual--;
                    }
                    cur += words[i]; // 拼接单词
                }
            }
            res.push_back(cur);
            start = end;
        }
        return res;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入 words:" << endl;
    getline(cin, line);
    vector<string> words = tool.split(line, ",");

    int maxWidth;
    cout << "输入 maxWidth:" << endl;
    cin >> maxWidth;

    vector<string> res = so.fullJustify(words, maxWidth);
    cout << "输出:" << endl;
    for (string& item: res){
        cout << "\"" << item << "\"" << endl;
    }
    return 0;
}
