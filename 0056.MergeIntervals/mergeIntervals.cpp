#include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > res;
        sort(intervals.begin(), intervals.end()); // 按照区间左端点排序
        int n = intervals.size();
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < n; i++){
            int l = intervals[i][0], r = intervals[i][1];
            if (l <= end){
                // 当前区间与之前区域有交集
                end = max(end, r);
            }
            else{
                // 新的区域
                res.push_back(intervals[i]);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({start, end}); // 最后一个区域
        return res;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<string> strIntervals = tool.split(line, " ");
    vector<vector<int> > intervals;
    for (string& strInterval: strIntervals){
        vector<int> interval = tool.stringToVector(strInterval);
        intervals.push_back(interval);
    }

    vector<vector<int> > mergeIntervsals = so.merge(intervals);
    cout << "输出:" << endl;
    for (vector<int>& mergeInterval: mergeIntervsals){
        string strMerge = tool.vectorToString(mergeInterval);
        cout << strMerge << " ";
    }

    return 0;
}
