#include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重 nums[i]
            for (int j = i + 1; j < n - 2; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 去重 nums[j]
                int l = j + 1, r = n - 1;
                while (l < r){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target){
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++; // 去重 nums[l]
                        while (l < r && nums[r] == nums[r - 1]) r--; // 去重 nums[r]
                        l++;
                        r--;
                    }
                    else if (sum < target) l++;
                    else r--;
                }
            }
        }
        return res;
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
    vector<vector<int> > res = so.fourSum(nums, target);
    cout << "输出:" << endl;
    for (auto item: res){
        string line = tool.vectorToString(item);
        cout << line << endl;
    }
    return 0;
}

