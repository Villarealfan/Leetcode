#include "../include/tools.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int close_sum = nums[0] + nums[1] + nums[2];
        int min_diff = abs(close_sum - target);
        int n = nums.size();
        for (int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                int diff = abs(sum - target);
                if (diff < min_diff){
                    min_diff = diff;
                    close_sum = sum;
                }
                if (sum < target){
                    l++;
                }
                else if (sum > target){
                    r--;
                }
                else{
                    return sum;
                }
            }
        }
        return close_sum;
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

    int output = so.threeSumClosest(nums, target);
    cout << "输出:" << output << endl;
    return 0;
}
