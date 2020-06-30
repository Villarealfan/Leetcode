#include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> item;
        dfs(res, item, candidates, target, 0);
        return res;
    }

private:
    void dfs(vector<vector<int> >& res, vector<int> item, vector<int>& candidates, int target, int start){
        if (target < 0) return;
        if (target == 0){
            res.push_back(item);
            return;
        }
        int n = candidates.size();
        for (int i = start; i < n; i++){
            item.push_back(candidates[i]);
            dfs(res, item, candidates, target - candidates[i], i);
            item.pop_back();
        }
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入 candidates:" << endl;
    getline(cin, line);
    vector<int> candidates = tool.stringToVector(line);

    cout << "输入 target:" << endl;
    getline(cin, line);
    int target = atoi(line.c_str());

    vector<vector<int> > res = so.combinationSum(candidates, target);
    cout << "输出:" << endl;
    for (auto& item: res){
        string output = tool.vectorToString(item);
        cout << output << endl;
    }
    return 0;
}
