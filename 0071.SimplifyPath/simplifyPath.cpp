#include "../include/tools.h"

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        istringstream ss(path);
        string item;
        while (getline(ss, item, '/')){
            // 若是 ".." ，则把上一层目录干掉
            if (item == ".."){
                if (!st.empty()){
                    st.pop();
                }
            }
            else if (item != "." && item != ""){
                // "." 和 "" 不加进来
                st.push(item);
            }
        }

        if (st.empty()) return "/"; 

        string res = "";
        while (!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }

        return res;
    }
};

int main(){
    Solution so;
    string path;
    cout << "输入:" << endl;
    getline(cin, path);

    string output = so.simplifyPath(path);
    cout << "输出:\n" << output << endl;
    return 0;
}
