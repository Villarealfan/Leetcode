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
    cout << "输入 nums:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    cout << "输入 target:" << endl;
    getline(cin, line);
    int target = stoi(line);

    vector<int> res = so.twoSum(nums, target);
    string output = tool.vectorToString(res);

    cout << "输出:\n" << output  << endl;
    
    return 0;
}
