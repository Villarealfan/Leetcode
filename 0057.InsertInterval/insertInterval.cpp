#include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > res;
        int index = 0, flag = 0;
        int n = intervals.size();
        vector<bool> used(n, false);
        // 前面没有相交的
        for (vector<int>& interval: intervals){
            if (interval[1] < newInterval[0]){
                res.push_back(interval);
                flag++;
            }
        }

        index = flag;
        // 中间相交的
        for (int i = index; i < n; i++){
            // 左端点相交
            if (newInterval[0] > intervals[i][0] && newInterval[0] <= intervals[i][1]){
                newInterval[0] = intervals[i][0];
                if (!used[i]) flag++;
                used[i] = true;
            }

            // 右端点相交
            if (newInterval[1] < intervals[i][1] && newInterval[1] >= intervals[i][0]){
                newInterval[1] = intervals[i][1];
                if (!used[i]) flag++;
                used[i] = true;
            }
        }
        res.push_back({newInterval[0], newInterval[1]});

        // 后面没相交的
        for (int i = flag; i < n; i++){
            if (newInterval[1] < intervals[i][0]){
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入 intervals:" << endl;
    getline(cin, line);
    vector<string> strIntervals = tool.split(line, " ");
    vector<vector<int> > intervals;
    for (string& strInterval: strIntervals){
        vector<int> interval = tool.stringToVector(strInterval);
        intervals.push_back(interval);
    }

    cout << "输入 newInterval:" << endl;
    getline(cin, line);
    vector<int> newInterval = tool.stringToVector(line);

    vector<vector<int> > res = so.insert(intervals, newInterval);
    string output;
    for (vector<int>& item: res){
        output += to_string(item[0]) + "," + to_string(item[1]) + " ";
    }
    cout << "输出:\n" << output << endl;
    return 0;
}
