# [题目](https://leetcode.com/problems/merge-intervals/)

* Merge Intervals

> Given a collection of intervals, merge all overlapping intervals.

* Example 1:

> Input: [[1,3],[2,6],[8,10],[15,18]]

> Output: [[1,6],[8,10],[15,18]]

> Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

* Example 2:

> Input: [[1,4],[4,5]]

> Output: [[1,5]]

> Explanation: Intervals [1,4] and [4,5] are considered overlapping.

* NOTE: 

> input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

# 代码

```cpp
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
```

# 思路

* 细节实现

* 有交集时，$l <= end$
![](https://raw.githubusercontent.com/Villarealfan/Leetcode/master/0056.MergeIntervals/1.jpg)

* 没有交集时
![](https://raw.githubusercontent.com/Villarealfan/Leetcode/master/0056.MergeIntervals/2.jpg)
