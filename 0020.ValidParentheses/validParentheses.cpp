#include "../include/tools.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if (st.empty()) return false;
                if (s[i] == ')' && st.top() != '(') return false;  
                if (s[i] == ']' && st.top() != '[') return false;  
                if (s[i] == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);

    bool res = so.isValid(line);
    string output = tool.boolToString(res);

    cout << "输出:\n" << output << endl;
    return 0;
}
