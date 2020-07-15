#include "../include/tools.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        int n = digits.size() - 1;
        for (int i = n; i >= 0; i--){
            if (digits[i] < 9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }
        // 进位问题
        if (digits[0] == 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> digits = tool.stringToVector(line);
    vector<int> res = so.plusOne(digits);
    string output = tool.vectorToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
