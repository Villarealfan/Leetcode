#include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重 nums[i]
            int l = i + 1, r = n - 1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]){
                        // 去重 nums[l]
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]){
                        // 去重 nums[r]
                        r--;
                    }
                    l++;
                    r--;
                }
                else if (sum < 0){
                    l++;
                }
                else{
                    r--;
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
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    cout << "ok" << endl;
    vector<vector<int> > res = so.threeSum(nums);
    cout << "输出:" << endl;
    for (auto item: res){
        string line = tool.vectorToString(item);
        cout << line << endl;
    }
    return 0;
}
