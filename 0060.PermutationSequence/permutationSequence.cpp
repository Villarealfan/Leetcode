#include "../include/tools.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "1"; // "123...n"
        
        int fac[9]; // fac[i]: (i+1)!
        fac[0] = 1;
        
        for (int i = 1; i < n; i++){
            fac[i] = fac[i - 1]*(i + 1);
            res.push_back(i +'1');
        }

        int index = 0; 
        int head; // 
        k--; // 从 0 计数
        while (n >= 2){
            head = k/fac[n - 2]; // 正确排序的首个数字对应位置  
            k -= head*fac[n - 2]; // 放好首个数字后的 1 排序 

            // 将首个数字放好
            if (head > 0){
                char temp = res[head + index];
                // 其他数字按原顺序后移
                for (int i = head + index - 1; i >= index; i--){
                    res[i + 1] = res[i];
                }
                res[index] = temp;
            }

            index++; 
            n--; 
        }
        return res;
    }
};

int main(){
    Solution so;

    int n, k;
    cout << "输入 n 和 k:" << endl;
    cin >> n >> k;
    string output = so.getPermutation(n, k);
    cout << "输出:\n" << output << endl;
    return 0;
}
