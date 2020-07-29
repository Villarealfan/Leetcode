#include "../include/tools.h"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            if (nums[l] == target) return true;
            if (nums[r] == target) return true;
            int mid = l + (r - l)/2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[r]){
                r--;
                continue;
            }
            else if (nums[mid] < nums[r]){
                if (target > nums[mid] && target < nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if (target > nums[l] && target < nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};


int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入 nums:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    int target;
    cout << "输入 target:" << endl;
    cin >> target;

    bool res = so.search(nums, target);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
