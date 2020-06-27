#include "../include/tools.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            int mid = l + (r - l)/2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < nums[r]){
                if (target > nums[mid] && target < nums[r]){
                    // target 在右半边
                    l = mid + 1;
                }
                else{
                    // target 在左半边
                    r = mid - 1;
                }
            }
            else{
                if (target > nums[l] && target < nums[mid]){
                    // target 在左半边
                    r = mid - 1;
                }
                else{
                    // target 在右半边
                    l = mid + 1;
                }
            }
        }
        return -1;
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

    int output = so.search(nums, target);
    cout << "输出:\n" << output << endl;
    return 0;
}
