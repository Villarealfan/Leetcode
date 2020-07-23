#include "../include/tools.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1, two = nums.size(), index = 0;
        while (index < two){
            if (nums[index] == 0){
                swap(nums[index++], nums[++zero]);
            }
            else if (nums[index] == 1){
                index++;
            }
            else{
                swap(nums[index++], nums[--two]);
            }
        }
        return;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    so.sortColors(nums);
    string output = tool.vectorToString(nums);
    cout << "输出:\n" << output << endl;
    return 0;
}
