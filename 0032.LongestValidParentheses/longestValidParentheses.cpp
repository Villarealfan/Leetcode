#include "../include/tools.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        st.push(-1); 
        int res = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '('){
                st.push(i);
            }
            else { // s[i] == ')'
                st.pop();
                if (!st.empty()){
                    /* '()'，此时-1的作用就是 1 - (-1) = 2
                     * 第 i 位前面的 '(' 不比 ')' 少
                     * 括号累计数 res 需要更新
                     * /
                    res = max(res, i - st.top());
                }
                else{
                    // 第 i 位前面的')'比'('多
                    st.push(i);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution so;
    
    string s;
    cout << "输入:" << endl;
    getline(cin, s);

    int output = so.longestValidParentheses(s);
    cout << "输出:\n" << output << endl;
    return 0;
}
