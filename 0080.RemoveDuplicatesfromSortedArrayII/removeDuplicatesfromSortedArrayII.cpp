#include "../include/tools.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int count = 2;
        for (int i = 2; i < n; i++){
            if (nums[i] != nums[count - 2]){
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};

int main(){
    Solution so;
    Tools tool;
    string line;

    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    int output = so.removeDuplicates(nums);
    cout << "输出:\n" << output << endl;
    return 0;
}
