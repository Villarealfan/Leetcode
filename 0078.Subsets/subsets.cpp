#include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> item;
        dfs(res, item, nums, 0);
        return res;
    }

private:
    void dfs(vector<vector<int> >& res, vector<int> item, vector<int>& nums, int k){
        if (k > nums.size()) return;
        res.push_back(item);
        for (int i = k; i < nums.size(); i++){
            item.push_back(nums[i]);
            dfs(res, item, nums, i + 1);
            item.pop_back();
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
    vector<vector<int> > res = so.subsets(nums);
    cout << "输出:" << endl;
    for (vector<int>& item: res){
        string itemStr = tool.vectorToString(item);
        cout << itemStr << endl;
    }
    return 0;
}
