# [题目](https://leetcode.com/problems/subsets-ii/)

* Subsets II

> Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

* Note: 

> The solution set must not contain duplicate subsets.

* Example:

```
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```

# 代码
```cpp
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
```


# 思路

* DFS

* 注意去重
