#include "../include/tools.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            int mid = l + (r - l)/2;
            if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入 nums:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);

    cout << "输入 target:" << endl;
    getline(cin, line);
    int target = atoi(line.c_str());

    int output = so.searchInsert(nums, target);
    cout << "输出:\n" << output << endl;
    return 0;
}
