#include "../include/tools.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = 1, n = nums.size();
        for (int i = 1; i < n; i++){
            if (nums[i] != nums[i - 1]){
                nums[len] = nums[i];
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
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);

    int len = so.removeDuplicates(nums);
    cout << "输出:\n" << len << endl;
    return 0;
}
