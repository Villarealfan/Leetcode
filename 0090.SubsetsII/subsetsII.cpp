# include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> item;
        dfs(res, item, nums, 0);
        return res;
    }

private:
    void dfs(vector<vector<int> >& res, vector<int> item, vector<int>& nums, int index){
        if (index > nums.size()){
            return;
        }
        res.push_back(item);
        for (int i = index; i < nums.size(); i++){
            if (i > index && nums[i] == nums[i - 1]) continue;
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
    vector<vector<int> > res = so.subsetsWithDup(nums);
    cout << "输出:" << endl;
    for (vector<int>& item: res){
        line = tool.vectorToString(item);
        cout << line << endl;
    }
    return 0;
}
