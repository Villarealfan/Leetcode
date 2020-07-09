# [题目] (https://leetcode.com/problems/insert-interval/)

* Insert Interval

> Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

> You may assume that the intervals were initially sorted according to their start times.

* Example 1:

> Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
> Output: [[1,5],[6,9]]

* Example 2:

> Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]

> Output: [[1,2],[3,10],[12,16]]

* Explanation: 

> Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

* NOTE: 

> input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

# 代码

```cpp
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
```

# 思路

* 细节实现
* 前面没相交的 + 中间相交的(头相交 + 尾相交) + 后面没相交的