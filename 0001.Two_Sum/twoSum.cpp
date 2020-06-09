/*=============================================================================
# 作者: 桂继宏
# 最近修改时间: 2020-06-09 15:13
# 文件名: twoSum.cpp
=============================================================================*/
/* You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Example:
   Given nums = [2, 7, 11, 15], target = 9, Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
*/

#include "../include/tools.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> index;
       int n = nums.size();
       for (int i = 0; i < n; i++){
           int other = target - nums[i];
           if (index.find(other) != index.end()){
               return {index[other], i};
           }
           index[nums[i]] = i;
       }
       return {-1, -1};
    }
};

int main(){
    Tools tool;
    Solution so;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    getline(cin, line);
    int target = stoi(line);

    vector<int> res = so.twoSum(nums, target);
    string output = tool.vectorToString(res);

    cout << "输出:\n" << output  << endl;
    
    return 0;
}
