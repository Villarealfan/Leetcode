#include "../include/tools.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0, n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] != val){
                nums[len] = val;
                len++;
            }
        }
        return len;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入 nums:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    cout << "输入 val:" << endl;
    getline(cin, line);
    int val = atoi(line.c_str());

    int len = so.removeElement(nums, val);
    cout << "输出:\n" << len << endl;
    return 0;
}
