#include "../include/tools.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int l = 0, r = nums.size() - 1;
        
        // 二分搜索找最左边的
        while (l <= r){
            int mid = l + (r - l)/2;
            if (nums[mid] == target){
                first = mid;
                r = mid - 1; // 找最左边的
            }
            else if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        if (first == -1){
            l = 0;
        }
        else{
            l = first;
        }
        r = nums.size() - 1;
        // 再次二分搜索找
        while (l <= r){
            int mid = l + (r - l)/2;
            if (nums[mid] == target){
                last = mid;
                l = mid + 1; // 找最右边的
            }
            else if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return {first, last};
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

    vector<int> res = so.searchRange(nums, target);
    string output = tool.vectorToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
