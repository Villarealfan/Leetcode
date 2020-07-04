#include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> item;
        vector<bool> used(nums.size(), false);
        dfs(res, item, nums, used);
        return res;
    }

private:
    void dfs(vector<vector<int> >& res, vector<int> item, const vector<int>& nums, vector<bool>& used){
        int m = item.size(), n = nums.size();
        if (m == n){
            res.push_back(item);
            return;
        }
        for (int i = 0; i < n; i++){
            if (used[i]) continue;
            item.push_back(nums[i]);
            used[i] = true;
            dfs(res, item, nums, used);
            item.pop_back();
            used[i] = false;
        }
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);

    vector<vector<int> > res = so.permute(nums);
    cout << "输出:" << endl; 
    for (auto &item:res){
        line = tool.vectorToString(item);
        cout << line << endl;
    }
    return 0;
}
