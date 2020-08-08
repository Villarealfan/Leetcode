#include "../include/tools.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < 1 << n; i++){
            res.push_back(i^(i>>1));
        }
        return res;
    }
};

int main(){
    Solution so;
    Tools tool;
    int n;
    cout << "输入:" << endl;
    cin >> n;
    vector<int> res = so.grayCode(n);
    string output = tool.vectorToString(res);
    cout << "输出:\n" << output <<endl;
}
