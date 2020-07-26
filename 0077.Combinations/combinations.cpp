#include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> item;
        dfs(res, item, n, k, 1);
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, vector<int> item, int n, int k, int index){
        if (k == 0){
            res.push_back(item);
            return;
        }

        for (int i = index; i <= n; i++){
            item.push_back(i);
            dfs(res, item, n, k - 1, i + 1);
            item.pop_back();
        }
    }
};

int main(){
    Solution so;
    Tools tool;

    int n, k;
    cout << "输入 n,k :" << endl;
    cin >> n >> k;
    vector<vector<int> > res = so.combine(n, k);
    cout << "输出:" << endl;
    for (vector<int>& item: res){
        string itemStr = tool.vectorToString(item);
        cout << itemStr << endl;
    }
    return 0;
}
